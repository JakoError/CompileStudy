//
// Created by JakoError on 2021/12/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "genllvm.h"
#include "list.h"
#include "ast.h"

String comm_space = "                                               ";

int mark = 1;
int ti = 0;
int fi = 0;
//break in if-else
int ei = 0;

bool cond = false;
bool in_while = false;
//for break and continue
String start = NULL;
String end = NULL;
//for FuncRParams use pointer
int pointer = 0;

void genCompUnit(Bean CompUnit, String *buff) {
    if (strcmp(CompUnit->value, "Decl") == 0)
        genDecl(CompUnit->beans[0], buff);
    else if (strcmp(CompUnit->value, "FuncDef") == 0)
        genFuncDef(CompUnit->beans[0], buff);
    else {
        printf("Error-Type not match CompUnit: '%s'", toString(CompUnit));
        exit(0);
    }
}

void genDecl(Bean Decl, String *buff) {
    if (strcmp(Decl->type, "VarDecl") == 0) {
        genVarDecl(Decl->beans[0], buff);
        return;
    } else {
        printf("Type not match VarDecl: '%s'", Decl->type);
    }
    genVarDecl(Decl->beans[0], buff);
}

void genVarDecl(Bean VarDecl, String *buff) {
    genVarDefs(VarDecl, buff);
}


void genVarDefs(Bean VarDefs, String *buff) {
    for (int i = 0; i < VarDefs->i; ++i)
        genVarDef(VarDefs->beans[i], buff);
}

void genVarDef(Bean VarDef, String *buff) {
    String s = newString(20 + strlen(comm_space));
    String *buff1 = newStringP();//array (type)
    String *buff2 = newStringP();//init store

    if (VarDef == NULL || strcmp(VarDef->type, "VarDef") != 0) {
        printf("Error-VarDef type dose not match '%s'", VarDef->value);
        exit(0);
    }
    //reserved id
    int *id_mark = NULL;//NULL is global
    if (range->next != NULL) {
        id_mark = malloc(sizeof(int));
        *id_mark = mark++;
    }

    //check type
    int align = 4;
    if (VarDef->i > 0 && strcmp(VarDef->beans[0]->type, "ConstExps") == 0) {
        // array type
        Bean ConstExps = VarDef->beans[0];
        int *array = genArrayExps(ConstExps, buff1);
        if (array == NULL) {
            printf("Error-VarDef '%s' array define should with const size value\n", VarDef->value);
            exit(0);
        }

        //save ArrayExps and %address to range
        //first line--address;second line--element
        int **var_arr = malloc(sizeof(int *) * 2);
        var_arr[0] = id_mark;
        var_arr[1] = array;
        putData(range->element, VarDef->value, var_arr);

        align = 16;

        //memset array
        //  %3 = bitcast [10 x [10 x i32]]* %2 to i8*
        //  call void @llvm.memset.p0i8.i64(i8* align 16 %3, i8 0, i64 400, i1 false)
        String memset_buff = newString(1000);
        sprintf(memset_buff + strlen(memset_buff),
                "  %%%d = bitcast %s* %%%d to i8*\n", mark++, *buff1, *id_mark);
        int size = 0;//size for memset
        for (int i = 1; i <= ConstExps->i; ++i) size += array[i] * 4;
        sprintf(memset_buff + strlen(memset_buff),
                "  call void @llvm.memset.p0i8.i64(i8* align 16 %%%d, i8 0, i64 %d, i1 false)\n", mark - 1, size);
        mystrcat(buff2, memset_buff);

        //handle initval
        if (VarDef->i == 2) {
            Bean InitVal = VarDef->beans[1];
            genArrayInits(InitVal, buff2, VarDef->value, ConstExps->i);
        }
    } else {
        //regular i32
        mystrcat(buff1, "i32");

        //save %address and 0 to range
        //first line--address;second line--element
        int **var_arr = malloc(sizeof(int *) * 2);
        var_arr[0] = id_mark;
        var_arr[1] = malloc(sizeof(int));//not array
        var_arr[1][0] = 0;
        putData(range->element, VarDef->value, var_arr);

        if (VarDef->i != 0) {//has initval
            //int init has to be exp
            Bean InitVal = VarDef->beans[0];
            if (InitVal->value != NULL) {
                printf("Error-VarDef '%s' init value should be INT NUMBER", VarDef->value);
                exit(0);
            }
            int *arg = genExps(InitVal->beans[0], buff2);
            String init = newString(100);
            if (arg != NULL) {
                sprintf(init, "  store i32 %d, i32* %%%d, align 4\n", *arg, *id_mark);
            } else {
                sprintf(init, "  store i32 %%%d, i32* %%%d, align 4\n", mark - 1, *id_mark);
            }
            mystrcat(buff2, init);
        }
    }

    sprintf(s, "  %%%d", *id_mark);
    s = genAlloca(s, *buff1, align);
    sprintf(s + strlen(s), "%s; define %s\n", comm_space, VarDef->value);

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    mystrcat(buff, *buff2);
    if (out)
        fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    freeBuff(buff2);
}

String genAlloca(String lval, String type, int align) {
    String s = newString(strlen(lval) + strlen(type) + 100);
    sprintf(s, "%s = alloca %s, align %d", lval, type, align);
    return s;
}

void genArrayInits(Bean InitVal, String *buff, String var_name, int layer) {
    int *array = malloc(sizeof(int) * (layer + 1));
    memset(array, 0, sizeof(int) * (layer + 1));
    array[0] = layer;
    genArrayInit(InitVal, buff, var_name, array, 0);
}

void genArrayInit(Bean InitVal, String *buff, String var_name, int *array, int stack) {
    if (InitVal->i == 0) {//{}
        array[stack]++;
        return;
    }

    if (InitVal->value == NULL || strcmp(InitVal->value, "{}") != 0) {//Exp generate
        Bean Stmt = beanInfo("Stmt", "assign");
        Bean LVal = beanInfo("LVal", var_name);
        Bean Exps = beanInfo("Exps", NULL);
        for (int i = 1; i <= array[0]; ++i) {
            Bean Number = beanInfo("Number", NULL);
            Number->iValue = array[i];
            addBean(Exps, Number);
        }
        addBean(LVal, Exps);
        Bean Exp = InitVal->beans[0];
        addBean(Stmt, LVal);
        addBean(Stmt, Exp);
        genStmt(Stmt, buff);

        array[array[0]]++;//end ++
        return;
    }
    stack++;
    Bean InitVals = InitVal->beans[0];

    for (int i = 0; i < InitVals->i; ++i) {
        genArrayInit(InitVals->beans[i], buff, var_name, array, stack);
    }

    //exit layer
    for (int i = stack; i <= array[0]; ++i)
        array[i] = 0;
    stack--;

    //pre layer stack move next
    if (stack != 0)
        array[stack]++;
}

void genFuncDef(Bean FuncFuncDef, String *buff) {
    String *buff_s = newStringP();
    String *buff1 = newStringP();//para
    String *buff2 = newStringP();//block
    String func_end = "}\n\n";

    //set mark 0
    mark = 0;

    int *type = (int *) malloc(sizeof(int));
    *type = strcmp(FuncFuncDef->type, "FuncDef-int") == 0;
    if (!putData(funcType, FuncFuncDef->value, &type)) {
        printf("Error-redefine function: '%s'", FuncFuncDef->value);
        exit(0);
    }

    mystrcat(buff_s, "; Function Attrs: noinline nounwind optnone uwtable\ndefine dso_local ");

    if (*type)
        mystrcat(buff_s, "i32 @");
    else
        mystrcat(buff_s, "void @");
    mystrcat(buff_s, FuncFuncDef->value);

    Bean Block;
    if (FuncFuncDef->i == 1) {
        int *para = (int *) malloc(sizeof(int));
        *para = 0;
        putData(funcPara, FuncFuncDef->value, &para);
        mystrcat(buff_s, "() #0 {\n");
        Block = FuncFuncDef->beans[0];
    } else {
        putData(funcPara, FuncFuncDef->value, genFuncFParams(FuncFuncDef->beans[0], buff1));
        mystrcat(buff_s, *buff1);
        mystrcat(buff_s, " #0 {\n");
        Block = FuncFuncDef->beans[1];
    }
    //add return to function end if necessary
    Bean BlockItems = Block->beans[0];

    if (BlockItems->i == 0//empty block or last not return
        || strcmp(toString(BlockItems->beans[BlockItems->i - 1]->beans[0]), "Stmt(return)") != 0) {
        if (*type)
            func_end = "  ret i32 0\n}\n\n";
        else
            func_end = "  ret void\n}\n\n";
    }


    genBlock(Block, buff2);

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff_s);
    mystrcat(buff, *buff2);
    mystrcat(buff, func_end);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff_s);
    freeBuff(buff1);
    freeBuff(buff2);
}

int **genFuncFParams(Bean FuncFParams, String *buff) {
    String *buff_s = newStringP();
    String *buff1 = newStringP();

    mystrcat(buff_s, "(");
    int **paras = (int **) malloc(sizeof(int *) * (FuncFParams->i + 1));
    paras[0] = &FuncFParams->i;
    for (int i = 0; i < FuncFParams->i; ++i) {
        paras[i + 1] = genFuncFParam(FuncFParams->beans[i], buff1);
        mystrcat(buff_s, *buff1);
        freeBuff(buff1);
        if (i == FuncFParams->i - 1)
            mystrcat(buff_s, ")");
        else
            mystrcat(buff_s, ", ");
    }

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff_s);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff_s);
    freeBuff(buff1);
    return paras;
}

int *genFuncFParam(Bean FuncFParam, String *buff) {
    String *buff_s = newStringP();
    String *buff1 = newStringP();

    int *array = NULL;
    if (FuncFParam->i == 0) {//i32
        mystrcat(buff_s, "i32 %");
    } else if (FuncFParam->beans[0]->i == 0) {//i32*
        mystrcat(buff_s, "i32* %");
        array = malloc(sizeof(int));
        *array = 0;
    } else {//array
        array = genArrayExps(FuncFParam->beans[0], buff1);
        if (array == NULL) {
            printf("Error-FuncFParam '%s' define should with const value", FuncFParam->value);
            exit(0);
        }

        mystrcat(buff_s, *buff1);
        mystrcat(buff_s, "* %");
    }
    mystrcat(buff_s, itos(mark++));

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff_s);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff_s);
    freeBuff(buff1);

    return array;
}

void genBlock(Bean Block, String *buff) {
    range = newList(range);
    genBlockItems(Block->beans[0], buff);
    exitRange();
}

void genBlockItems(Bean BlockItems, String *buff) {
    for (int i = 0; i < BlockItems->i; ++i) {
        genBlockItem(BlockItems->beans[i], buff);
    }
}

void genBlockItem(Bean BlockItem, String *buff) {
    if (strcmp(BlockItem->value, "Decl") == 0)
        genDecl(BlockItem->beans[0], buff);
    else if (strcmp(BlockItem->value, "Stmt") == 0)
        genStmt(BlockItem->beans[0], buff);
    else {
        printf("Error-BlockItem dose not match value:%s", BlockItem->value);
        exit(0);
    }
}

void genIf(Bean If, String *buff) {
    String s1 = newString(100 + strlen(comm_space));//if start
    String s2 = newString(100 + strlen(comm_space));//if br end and end:
    String *buff1 = newStringP();
    String *buff2 = newStringP();

    int *cond_result = genCond(If->beans[0], buff1);

    if (cond_result == NULL) {
        sprintf(s1 + strlen(s1), "%%t%d:%s;if-body\n", ti, comm_space);
        sprintf(s2 + strlen(s2), "  br %%f%d\n\n", fi);
        sprintf(s2 + strlen(s2), "%%f%d:%s;if-end\n", fi, comm_space);
        ti++;
        fi++;
    } else if (*cond_result) {//always true
        printf("warning:expression always true\n");
    } else {//always false
        printf("warning:expression always false can't reach the if-body sentence\n");
        return;
    }

    genStmt(If->beans[1], buff2);

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff1);
    mystrcat(buff, s1);
    mystrcat(buff, *buff2);
    mystrcat(buff, s2);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    freeBuff(buff2);
}

void genIfElse(Bean IfElse, String *buff) {
    String s1 = newString(100 + strlen(comm_space));//if start
    String s2 = newString(100);//if br end
    String s3 = newString(100 + strlen(comm_space));//else start
    String s4 = newString(100 + strlen(comm_space));//else br end and end:
    String *buff1 = newStringP();//cond
    String *buff2 = newStringP();//if-body
    String *buff3 = newStringP();//else-body

    int *cond_result = genCond(IfElse->beans[0], buff1);

    if (cond_result == NULL) {
        sprintf(s1 + strlen(s1), "%%t%d:%s;if-body\n", ti, comm_space);
        sprintf(s3 + strlen(s3), "%%f%d:%s;else-body\n", fi, comm_space);
        ti++;
        fi++;
        genStmt(IfElse->beans[1], buff2);//if-body
        genStmt(IfElse->beans[2], buff3);//else-body

        sprintf(s2 + strlen(s2), "  br label %%e%d\n\n", ei);//if br end
        sprintf(s4 + strlen(s4), "  br label %%e%d\n\n", ei);//else br end
        sprintf(s4 + strlen(s4), "%%e%d:%s;if-else-end\n", ei, comm_space);
        ei++;
        ti++;
        fi++;
    } else if (*cond_result) {//always true
        printf("warning:expression always true can't reach the else-body sentence\n");
        genStmt(IfElse->beans[1], buff2);//if-body
    } else {//always false
        printf("warning:expression always false can't reach the if-body sentence\n");
        genStmt(IfElse->beans[2], buff3);//else-body
    }

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff1);
    mystrcat(buff, s1);
    mystrcat(buff, *buff2);
    mystrcat(buff, s2);
    mystrcat(buff, s3);
    mystrcat(buff, *buff3);
    mystrcat(buff, s4);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    freeBuff(buff2);
    freeBuff(buff3);
}

void genWhile(Bean While, String *buff) {
    String s1 = newString(100);//while br cond
    String s2 = newString(100 + strlen(comm_space));//while
    String s3 = newString(100 + strlen(comm_space));//while br cond and end:
    String *buff1 = newStringP();
    String *buff2 = newStringP();

    //while special br to set start(continue-ues)
    sprintf(s1 + strlen(s1), "  br label %%%d\n\n%%%d:\n", mark, mark);
    int cond_start = mark++;

    int *cond_result = genCond(While->beans[0], buff1);

    if (cond_result == NULL) {
        sprintf(s2 + strlen(s2), "%%t%d:%s;while-body\n", ti, comm_space);
        sprintf(s3 + strlen(s3), "  br label %%%d\n\n", cond_start);
        sprintf(s3 + strlen(s3), "%%f%d:%s;while-end\n", fi, comm_space);

        start = malloc(20);
        end = malloc(20);
        sprintf(start, "%%%d", cond_start);
        sprintf(end, "%%f%d", fi);

        ti++;
        fi++;
    } else if (*cond_result) {//always true
        printf("warning:expression always true---endless while loop\n");
    } else {//always false
        printf("warning:expression always false can't reach the while-body sentence\n");
        return;
    }
    genStmt(While->beans[1], buff2);
    
    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s1);
    mystrcat(buff, *buff1);
    mystrcat(buff, s2);
    mystrcat(buff, *buff2);
    mystrcat(buff, s3);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    freeBuff(buff2);
}

int *genCond(Bean Cond, String *buff) {
    String s = newString(1000);
    String *buff1 = newStringP();

    if (strcmp(Cond->beans[0]->type, "LVal") == 0) {
        printf("Error-please set condition with \"'id' != 0\" or \"'id' == 0\" when call id:%s",
               Cond->beans[0]->value);
        exit(0);
    }

    cond = true;
    int *arg = genExps(Cond->beans[0], buff1);
    cond = false;

    if (arg != NULL) return arg;

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff1);
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    return NULL;
}

void genStmt(Bean Stmt, String *buff) {
    String s = newString(1000);

    if (strcmp(Stmt->type, "Stmt") != 0) {
        printf("Stmt type not match: '%s'", toString(Stmt));
        exit(0);
    }
    if (strcmp(Stmt->value, "assign") == 0) {
        int *arg = genExps(Stmt->beans[1], buff);
        int pre_mark = mark - 1;

        String var_p = genLVal(Stmt->beans[0], buff, 0);
        if (arg == NULL)
            sprintf(s + strlen(s), "  store i32 %%%d, ", pre_mark);
        else
            sprintf(s + strlen(s), "  store i32 %d, ", *arg);

        if (var_p == NULL)//pointer
            sprintf(s + strlen(s), "i32* %%%d, align 4\n", mark - 1);
        else//id
            sprintf(s + strlen(s), "i32* %s, align 16\n", var_p);

    } else if (strcmp(Stmt->value, "Exp") == 0) {
        genExps(Stmt->beans[0], buff);
    } else if (strcmp(Stmt->value, "block") == 0) {
        genBlock(Stmt->beans[0], buff);
    } else if (strcmp(Stmt->value, "if") == 0) {
        genIf(Stmt, buff);
    } else if (strcmp(Stmt->value, "if-else") == 0) {
        genIfElse(Stmt, buff);
    } else if (strcmp(Stmt->value, "while") == 0) {
        in_while = true;
        genWhile(Stmt, buff);
        in_while = false;
    } else if (strcmp(Stmt->value, "break") == 0) {
        if (!in_while) errorPrint("'break' only use in while");
        sprintf(s + strlen(s), "  br label %s\n\n", end);
    } else if (strcmp(Stmt->value, "continue") == 0) {
        if (!in_while) errorPrint("'continue' only use in while");
        sprintf(s + strlen(s), "  br label %s\n\n", start);
    } else if (strcmp(Stmt->value, "return") == 0) {
        if (Stmt->i == 0)
            sprintf(s + strlen(s), "  ret void\n");
        else {
            int *arg = genExps(Stmt->beans[0], buff);
            if (arg != NULL)
                sprintf(s + strlen(s), "  ret i32 %d\n", *arg);
            else
                sprintf(s + strlen(s), "  ret i32 %%%d\n", mark - 1);
        }
    }

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);
}

/**
 * @return array of ArrayExps [0] length [...] element
 */
int *genArrayExps(Bean ArrayExps, String *buff) {
    String array_str = newString(20 * ArrayExps->i);
    int *array = malloc(sizeof(int) * (ArrayExps->i + 1));
    array[0] = ArrayExps->i;
    for (int j = 0; j < ArrayExps->i; ++j) {
        int *arg = genExps(ArrayExps->beans[j], buff);
        if (arg == NULL) {
//            free(array_str);
            return NULL;
        }
        array[j + 1] = *arg;
        sprintf(array_str + strlen(array_str), "[%d x ", *arg);
    }
    sprintf(array_str + strlen(array_str), "i32");
    for (int j = 0; j < ArrayExps->i; ++j)
        sprintf(array_str + strlen(array_str), "]");

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, array_str);
    if (out) fprintf(genOut, "%s", *buff);

    return array;
}

/**
 * LVal has two usage 1:store 2.read
 * \n set 0 - store 1 - read
 * @param LVal LVal Bean
 * @param io 0 - store 1 - read
 * @return String of \@i or %i(only store available)
 */
String genLVal(Bean LVal, String *buff, bool io) {
    String s = newString(1000);
    String *buff1 = newStringP();//pointer read

    if (strcmp(LVal->type, "LVal") != 0) errorPrint("LVal type not match");
    //find var in range
    int **value = getVarValue(LVal->value);
    //array can not beyond initial size
    int count = LVal->i == 0 ? 0 : LVal->beans[0]->i;
    if (pointer == 0 && count != value[1][0]) {
        printf("Error-value of lval:%s should be int", LVal->value);
        exit(0);
    }
    if (pointer != 0 && pointer != value[1][0] - count) {
        printf("Error-array type '%s' dose not match function type", LVal->value);
        exit(0);
    }
    pointer = 0;//consume pointer

    //generate code
    //get var name(global) or address(local)
    String var_p = malloc(20 + strlen(LVal->value));
    if (value[0] == NULL) {
        //global
        sprintf(var_p, "@%s", LVal->value);
    } else {
        //local
        sprintf(var_p, "%%%d", **value);
    }

    bool add_load = true;

    if (value[1][0] == 0) {//0 element when define
        if (io) {//read
            sprintf(s + strlen(s), "  %%%d = load i32, i32* %s, align 4\n", mark++, var_p);
        }
        //store do nothing
    } else {//array define
        //%4 = getelementptr inbounds [22 x [33 x [44 x i32]]], [22 x [33 x [44 x i32]]]* %2, i64 0, i64 11
        //%5 = getelementptr inbounds [33 x [44 x i32]], [33 x [44 x i32]]* %4, i64 0, i64 23
        //%6 = getelementptr inbounds [44 x i32], [44 x i32]* %5, i64 0, i64 34
        Bean Exps = LVal->beans[0];
        int *pre_mark = malloc(sizeof(int) * Exps->i);
        int **args = malloc(sizeof(int *) * (Exps->i + 2));//remain for addition
        for (int i = 0; i < Exps->i; ++i) {
            args[i] = genExps(Exps->beans[i], buff);
            pre_mark[i] = mark - 1;
        }
        //if pointer not match add an 0
        if (Exps->i < value[1][0]) {
            args[count] = malloc(sizeof(int));
            *args[count] = 0;
            count++;
            add_load = false;
        }

        for (int i = 0; i < count; ++i) {
            String mark_str = newString(20);
            sprintf(mark_str, "  %%%d", mark++);
            mystrcat(buff1, mark_str);
//            free(mark_str);

            mystrcat(buff1, " = getelementptr inbounds ");

            String array_str = newString(20 * value[1][0]);
            for (int j = i + 1; j <= value[1][0]; ++j)
                sprintf(array_str + strlen(array_str), "[%d x ", value[1][j]);
            sprintf(array_str + strlen(array_str), "i32");
            for (int j = i + 1; j <= value[1][0]; ++j)
                sprintf(array_str + strlen(array_str), "]");
            mystrcat(buff1, array_str);
            mystrcat(buff1, ", ");
            mystrcat(buff1, array_str);
            mystrcat(buff1, "* ");
//            free(array_str);

            String end_call = newString(100);
            if (i == 0)//call the id of var
                sprintf(end_call + strlen(end_call), "%s, ", var_p);
            else//pre cal all arg so mark-1 work finely
                sprintf(end_call + strlen(end_call), "%%%d, ", mark - 1);

            if (args[i] != NULL)
                sprintf(end_call + strlen(end_call), "i32 0, i32 %d\n", *args[i]);
            else
                sprintf(end_call + strlen(end_call), "i32 0, i32 %%%d\n", pre_mark[i]);
            mystrcat(buff1, end_call);
//            free(end_call);
        }
        if (io) {
            //read
            //load from pointer
            if (add_load) {
                sprintf(s + strlen(s), "  %%%d = load i32, i32* %%%d, align 4\n", mark, mark - 1);
                mark++;
            }
        } else {
            //store update var_p to last pointer
            //notify store to use mark-1 pointer
//            free(var_p);
            var_p = NULL;
        }
    }

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff1);
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff1);
    if (io)
        return NULL;
    else
        return var_p;
}

/**
 * generate code for every exp
 * @param !Exp !Exps !PrimaryExp Number LVal UnaryExp MulExp AddExp RelExp EqExp !LAndExp !LOrExp !ConstExps !ConstExp
 * @return result pointer
 */
int *genExps(Bean Exp, String *buff) {
    //no output!!

    if (Exp == NULL || Exp->type == NULL) return NULL;
    if (strcmp(Exp->type, "Number") == 0) {
        int *result = (int *) malloc(sizeof(int));
        *result = Exp->iValue;
        return result;
    }
    if (strcmp(Exp->type, "LVal") == 0) {//in exp LVal to read
        genLVal(Exp, buff, 1);
        return NULL;
    }
    if (strcmp(Exp->type, "UnaryExp") == 0)
        return genUnaryExp(Exp, buff);
    if (strcmp(Exp->type, "UnaryExp-function") == 0) {
        genUnaryExpFunc(Exp, buff);
        return NULL;
    }
    if (strcmp(Exp->type, "MulExp") == 0)
        return genMulExp(Exp, buff);
    if (strcmp(Exp->type, "AddExp") == 0)
        return genAddExp(Exp, buff);
    if (strcmp(Exp->type, "RelExp") == 0)
        return genRelExp(Exp, buff);
    if (strcmp(Exp->type, "EqExp") == 0)
        return genEqExp(Exp, buff);
    if (strcmp(Exp->type, "LAndExp") == 0)
        return genLAndExp(Exp, buff);
    if (strcmp(Exp->type, "LOrExp") == 0)
        return genLOrExp(Exp, buff);

    printf("Error-Exp type dose not match '%s'", Exp->type);
    exit(0);
}

int *genUnaryExp(Bean UnaryExp, String *buff) {
    String s = newString(100);

    int *arg = genExps(UnaryExp->beans[0], buff);

    if (arg != NULL) {
        if (*UnaryExp->value == '-')
            *arg = -*arg;
        else if (*UnaryExp->value == '!')
            *arg = (*arg == 0);
        return arg;
    }

    //generate code
    sprintf(s + strlen(s), "  %%%d = ", mark);
    mark++;
    if (*UnaryExp->value == '-') {
        sprintf(s + strlen(s), "sub nsw i32 0, %%%d\n", mark - 1);
    } else if (*UnaryExp->value == '!') {
        //only legal in condition
        if (!cond)
            errorPrint("'!' can only be used in Condition");
        sprintf(s + strlen(s), "icmp ne i32 %%%d, 0\n", mark - 1);
    }

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);

    return arg;
}

void genUnaryExpFunc(Bean UnaryExp, String *buff) {
    String *buff_s = newStringP();
    String *buff1 = newStringP();//(...)
    String *buff2 = newStringP();//exp

    if (UnaryExp->value == NULL)
        errorPrint("func name is null");
    //check function name exist
    int ***para = getValue(funcPara, UnaryExp->value);
    int ***type = getValue(funcType, UnaryExp->value);
    if (para == NULL || type == NULL) {//function not found
        printf("ERROR-function:%s not define", UnaryExp->value);
        exit(0);
    }
    //get the count of real para
    int r_count = UnaryExp->i == 0 ? 0 : UnaryExp->beans[0]->i;
    if (***para != r_count) {
        printf("ERROR-function:%s param num not match:%d-%d", UnaryExp->value, ***para, r_count);
        exit(0);
    }

    //get all real para
    if (r_count == 0) {
        mystrcat(buff1, "()\n");
    } else {
        mystrcat(buff1, "(");
        Bean FuncRParams = UnaryExp->beans[0];
        int **paras = *para;
        for (int i = 0; i < FuncRParams->i; ++i) {
            if (paras[i + 1] == NULL)//int
                mystrcat(buff1, "i32 ");
            else {//int[]...
                String array_str = newString(20 * paras[i + 1][0]);
                for (int j = 1; j <= paras[i + 1][0]; ++j)
                    sprintf(array_str + strlen(array_str), "[%d x ", paras[i + 1][j]);
                sprintf(array_str + strlen(array_str), "i32");
                for (int j = 1; j <= paras[i + 1][0]; ++j)
                    sprintf(array_str + strlen(array_str), "]");
                sprintf(array_str + strlen(array_str), "* ");
                mystrcat(buff1, array_str);
            }
            pointer = paras[i + 1] == NULL ? 0 : paras[i + 1][0] + 1;
            int *r_para = genExps(FuncRParams->beans[i], buff2);
            pointer = 0;

            if (r_para == NULL) {
                mystrcat(buff1, "%");
                mystrcat(buff1, itos(mark - 1));
            } else
                mystrcat(buff1, itos(*r_para));
            //separate
            if (i != FuncRParams->i - 1) mystrcat(buff1, ", ");
            else mystrcat(buff1, ")\n");
        }
    }

    //judge the type of function
    if (***type == 1) {
        String mark_str = newString(20);
        sprintf(mark_str, "  %%%d", mark++);
        mystrcat(buff_s, mark_str);
//        free(mark_str);

        mystrcat(buff_s, " = call i32 @");
    } else
        mystrcat(buff_s, "  call void @");
    mystrcat(buff_s, UnaryExp->value);

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, *buff2);
    mystrcat(buff, *buff_s);
    mystrcat(buff, *buff1);
    if (out) fprintf(genOut, "%s", *buff);

    freeBuff(buff_s);
    freeBuff(buff1);
    freeBuff(buff2);
}

int *genMulExp(Bean MulExp, String *buff) {
    String s = newString(100);

    //%4 = mul nsw i32 %3, 2
    //%5 = sdiv i32 %4, 2
    //%5 = srem i32 %4, 2
    int i1;
    int i2;
    int *arg1 = genExps(MulExp->beans[0], buff);
    if (arg1 == NULL) i1 = mark - 1;
    int *arg2 = genExps(MulExp->beans[1], buff);
    if (arg2 == NULL) i2 = mark - 1;

    if (arg1 != NULL && arg2 != NULL) {
        int *result = (int *) malloc(sizeof(int));
        if (*MulExp->value == '*')
            *result = *arg1 * *arg2;
        else if (*MulExp->value == '/')
            *result = *arg1 / *arg2;
        else
            *result = *arg1 % *arg2;
        return result;
    }

    sprintf(s + strlen(s), "  %%%d = ", mark);
    mark++;
    if (*MulExp->value == '*')
        sprintf(s + strlen(s), "mul nsw ");
    else if (*MulExp->value == '/')
        sprintf(s + strlen(s), "sidv ");
    else
        sprintf(s + strlen(s), "srem ");

    if (arg1 != NULL) sprintf(s + strlen(s), "%d", *arg1);
    else sprintf(s + strlen(s), "i32 %%%d", i1);
    if (arg2 != NULL) sprintf(s + strlen(s), "%d", *arg2);
    else sprintf(s + strlen(s), "i32 %%%d", i2);
    sprintf(s + strlen(s), "\n");

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);

    return NULL;
}

int *genAddExp(Bean AddExp, String *buff) {
    String s = newString(1000);

    //add nsw
    //sub nsw
    int i1;
    int i2;
    int *arg1 = genExps(AddExp->beans[0], buff);
    if (arg1 == NULL) i1 = mark - 1;
    int *arg2 = genExps(AddExp->beans[1], buff);
    if (arg2 == NULL) i2 = mark - 1;

    if (arg1 != NULL && arg2 != NULL) {
        int *result = (int *) malloc(sizeof(int));
        if (*AddExp->value == '+')
            *result = *arg1 + *arg2;
        else
            *result = *arg1 - *arg2;
        return result;
    }

    sprintf(s + strlen(s), "  %%%d = ", mark);
    mark++;
    if (*AddExp->value == '+')
        sprintf(s + strlen(s), "add nsw ");
    else
        sprintf(s + strlen(s), "sub nsw ");

    if (arg1 != NULL) sprintf(s + strlen(s), "%d, ", *arg1);
    else sprintf(s + strlen(s), "i32 %%%d, ", i1);
    if (arg2 != NULL) sprintf(s + strlen(s), "%d", *arg2);
    else sprintf(s + strlen(s), "i32 %%%d", i2);
    sprintf(s + strlen(s), "\n");

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);

    return NULL;
}

int *genRelExp(Bean RelExp, String *buff) {
    String s = newString(1000);

    //icmp sgt
    //icmp slt
    //icmp sge
    //icmp sle
    int i1;
    int i2;
    int *arg1 = genExps(RelExp->beans[0], buff);
    if (arg1 == NULL) i1 = mark - 1;
    int *arg2 = genExps(RelExp->beans[1], buff);
    if (arg2 == NULL) i2 = mark - 1;

    if (arg1 != NULL && arg2 != NULL) {
        int *result = (int *) malloc(sizeof(int));
        if (strlen(RelExp->value) == 1) {
            if (*RelExp->value == '<')
                *result = *arg1 < *arg2;
            else
                *result = *arg1 > *arg2;
        } else {
            if (*RelExp->value == '<')
                *result = *arg1 <= *arg2;
            else
                *result = *arg1 >= *arg2;
        }

        return result;
    }

    sprintf(s + strlen(s), "  %%%d = ", mark);
    mark++;
    if (strlen(RelExp->value) == 1) {
        if (*RelExp->value == '<')
            sprintf(s + strlen(s), "icmp sgt ");
        else
            sprintf(s + strlen(s), "icmp slt ");
    } else {
        if (*RelExp->value == '<')
            sprintf(s + strlen(s), "icmp sge ");
        else
            sprintf(s + strlen(s), "icmp sle ");
    }

    if (arg1 != NULL) sprintf(s + strlen(s), "%d, ", *arg1);
    else sprintf(s + strlen(s), "i32 %%%d, ", i1);
    if (arg2 != NULL) sprintf(s + strlen(s), "%d", *arg2);
    else sprintf(s + strlen(s), "i32 %%%d", i2);
    sprintf(s + strlen(s), "\n");

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);
    return NULL;
}

int *genEqExp(Bean EqExp, String *buff) {
    String s = newString(1000);

    //icmp eq
    //icmp slt
    int i1;
    int i2;
    int *arg1 = genExps(EqExp->beans[0], buff);
    if (arg1 == NULL) i1 = mark - 1;
    int *arg2 = genExps(EqExp->beans[1], buff);
    if (arg2 == NULL) i2 = mark - 1;

    if (arg1 != NULL && arg2 != NULL) {
        int *result = (int *) malloc(sizeof(int));
        if (*EqExp->value == '=')
            *result = *arg1 == *arg2;
        else
            *result = *arg1 != *arg2;
        return result;
    }

    sprintf(s + strlen(s), "  %%%d = ", mark);
    mark++;
    if (*EqExp->value == '=')
        sprintf(s + strlen(s), "icmp eq ");
    else
        sprintf(s + strlen(s), "icmp ne ");

    if (arg1 != NULL) sprintf(s + strlen(s), "%d, ", *arg1);
    else sprintf(s + strlen(s), "i32 %%%d, ", i1);
    if (arg2 != NULL) sprintf(s + strlen(s), "%d", *arg2);
    else sprintf(s + strlen(s), "i32 %%%d", i2);
    sprintf(s + strlen(s), "\n");

    bool out = buff == NULL;
    if (out) buff = newStringP();
    mystrcat(buff, s);
    if (out) fprintf(genOut, "%s", *buff);
    return NULL;
}

int *genLAndExp(Bean LAndExp, String *buff) {
    String s = newString(1000);
    String s1 = newString(1000);
    String s2 = newString(1000);
    String *buff1 = newStringP();
    String *buff2 = newStringP();
    //interrupt

    //ban unit LVal in condition
    if (strcmp(LAndExp->beans[0]->type, "LVal") == 0) {
        printf("Error-please set condition with \"'id' != 0\" or \"'id' == 0\" when call id:%s",
               LAndExp->beans[0]->value);
        exit(0);
    }
    if (strcmp(LAndExp->beans[1]->type, "LVal") == 0) {
        printf("Error-please set condition with \"'id' != 0\" or \"'id' == 0\" when call id:%s",
               LAndExp->beans[1]->value);
        exit(0);
    }


    int *arg1 = genExps(LAndExp->beans[0], buff1);
    //pre consume
    int pre_t = ti++;
    int pre_f = fi++;
    int *arg2 = genExps(LAndExp->beans[1], buff2);

    //num interrupt 0
    if (arg1 != NULL && !*arg1) return arg1;
    if (arg2 != NULL && !*arg2) return arg2;

    //only one
    if (arg1 != NULL || arg2 != NULL) {
        //exist one is num
        //if only one is generated another one won't have code the mark is work finely
        String p;
        if (arg1 == NULL) p = *buff1;
        if (arg2 == NULL) p = *buff2;

        Bean Exp = arg1 == NULL ? LAndExp->beans[0] : LAndExp->beans[1];
        //only generate br when unit
        if (*Exp->value != '&' && *Exp->value != '|')
            sprintf(s + strlen(s), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, ti, fi);

        bool out = buff == NULL;
        if (out) buff = newStringP();
        mystrcat(buff, p);
        mystrcat(buff, s);
        if (out) fprintf(genOut, "%s", *buff);
    } else {
        bool unit1 = *LAndExp->beans[0]->value != '&' && *LAndExp->beans[0]->value != '|';
        bool unit2 = *LAndExp->beans[1]->value != '&' && *LAndExp->beans[1]->value != '|';
        //double
        if (unit1) {
            //unit one
            //pre_t pre_f in case second is nesting
            sprintf(s1 + strlen(s1), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, pre_t, pre_f);
        }
        if (unit2) {
            //second unit
            //optimize fi usage
            fi--;
            sprintf(s2 + strlen(s2), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, ti, fi);
        }
        if (!unit1 && !unit2) {
            //first fail merge to second fail
            sprintf(s1 + strlen(s1), "%%f%d:\n  br label %%f%d\n\n", pre_f, fi);
        }
        //connect with pre_ti
        sprintf(s1 + strlen(s1), "%%t%d:\n", pre_t);

        bool out = buff == NULL;
        if (out) buff = newStringP();
        mystrcat(buff, *buff1);
        mystrcat(buff, s1);
        mystrcat(buff, *buff2);
        mystrcat(buff, s2);
        if (out) fprintf(genOut, "%s", *buff);
    }

    freeBuff(buff1);
    freeBuff(buff2);

    return NULL;
}

int *genLOrExp(Bean LOrExp, String *buff) {
    String s = newString(1000);
    String s1 = newString(1000);
    String s2 = newString(1000);
    String *buff1 = newStringP();
    String *buff2 = newStringP();
    //interrupt
    if (strcmp(LOrExp->beans[0]->type, "LVal") == 0) {
        printf("Error-please set condition with \"'id' != 0\" or \"'id' == 0\" when call id:%s",
               LOrExp->beans[0]->value);
        exit(0);
    }
    if (strcmp(LOrExp->beans[1]->type, "LVal") == 0) {
        printf("Error-please set condition with \"'id' != 0\" or \"'id' == 0\" when call id:%s",
               LOrExp->beans[1]->value);
        exit(0);
    }

    int *arg1 = genExps(LOrExp->beans[0], buff1);
    //pre consume
    int pre_t = ti++;
    int pre_f = fi++;
    int *arg2 = genExps(LOrExp->beans[1], buff2);

    //num interrupt 1
    if (arg1 != NULL && *arg1) return arg1;
    if (arg2 != NULL && *arg2) return arg2;

    //only one
    if (arg1 != NULL || arg2 != NULL) {
        //exist one is num
        //if only one is generated another one won't have code the mark is work finely
        String p;
        if (arg1 == NULL) p = *buff1;
        if (arg2 == NULL) p = *buff2;

        Bean Exp = arg1 == NULL ? LOrExp->beans[0] : LOrExp->beans[1];
        //only generate br when unit
        if (*Exp->value != '&' && *Exp->value != '|')
            sprintf(s + strlen(s), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, ti, fi);

        bool out = buff == NULL;
        if (out) buff = newStringP();
        mystrcat(buff, p);
        mystrcat(buff, s);
        if (out) fprintf(genOut, "%s", *buff);
    } else {
        bool unit1 = *LOrExp->beans[0]->value != '&' && *LOrExp->beans[0]->value != '|';
        bool unit2 = *LOrExp->beans[1]->value != '&' && *LOrExp->beans[1]->value != '|';
        //double
        if (unit1) {
            //unit one
            //pre_t pre_f in case second is nesting
            sprintf(s1 + strlen(s1), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, pre_t, pre_f);
        }
        if (unit2) {
            //second unit
            //optimize ti usage
            ti--;
            sprintf(s2 + strlen(s2), "  br i1 %%%d, label %%t%d, label %%f%d\n\n", mark - 1, ti, fi);
        }
        if (!unit1 && !unit2) {
            //first true merge to second true
            sprintf(s1 + strlen(s1), "%%t%d:\n  br label %%t%d\n\n", pre_t, ti);
        }
        //connect with pre_fi
        sprintf(s1 + strlen(s1), "%%f%d:\n", pre_f);

        bool out = buff == NULL;
        if (out) buff = newStringP();
        mystrcat(buff, *buff1);
        mystrcat(buff, s1);
        mystrcat(buff, *buff2);
        mystrcat(buff, s2);
        if (out) fprintf(genOut, "%s", *buff);
    }

    return NULL;
}

/**
 * provide auto realloc expand String
 * @warning
 * dst has to generate first *dst is nullable
 * \n otherwise realloc will fail
 * @param dst pointer of Destination String
 * @param src Source String
 * @return updated dst
 */
String mystrcat(String *dst, String src) {
    if (dst == NULL) return NULL;
    if (src == NULL || strlen(src) == 0) return *dst;
    int r;
    if (*dst == NULL) {
        *dst = malloc(sizeof(char) * (strlen(src) + 100));
        r = 0;
    } else {
        *dst = realloc(*dst, sizeof(char) * (strlen(*dst) + strlen(src) + 100));
        r = (int) strlen(*dst);
    }

    for (int i = 0; i < strlen(src); ++i)
        (*dst)[r++] = src[i];
    (*dst)[r] = '\0';
    return *dst;
}

String newString(size_t size) {
    String str = malloc(size);
    str[0] = '\0';
    return str;
}

String *newStringP() {
    String *str_p = malloc(sizeof(String));
    *str_p = NULL;
    return str_p;
}

void freeBuff(String *buff) {
    free(*buff);
    *buff = NULL;
}

void errorPrint(String str) {
    printf("\nError-%s", str);
    exit(0);
}