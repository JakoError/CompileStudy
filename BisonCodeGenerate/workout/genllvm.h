//
// Created by JakoError on 2021/12/15.
//

#ifndef COMPILESTUDY_GENLLVM_H
#define COMPILESTUDY_GENLLVM_H

#include "ast.h"
#include "hashMap.h"

typedef struct glo_init{
    Bean Init;
    String var_name;
    int layer;
    bool is_const;
} *GlobalInit;

int glo_arr_i;
GlobalInit glo_arr;

FILE *genOut;

HashMap funcType;
HashMap funcPara;


void genCompUnit(Bean CompUnit, String *buff);

void genDecl(Bean Decl, String *buff);

void genVarDecl(Bean VarDecl, String *buff, bool is_const);

void genVarDefs(Bean VarDefs, String *buff, bool is_const);

void genVarDef(Bean VarDef, String *buff, bool is_const);

void genGlobal(Bean VarDef, String *buff, bool is_const);

void genFuncDef(Bean FuncFuncDef, String *buff);

void genArrayInits(Bean InitVal, String *buff, String var_p, int layer);

void genArrayInit(Bean InitVal, String *buff, String var_p, int *array, int stack);

String genAlloca(String lval, String type, int align);

int **genFuncFParams(Bean FuncFParams, String *buff);

int *genFuncFParam(Bean FuncFParam, String *buff);

void genBlock(Bean Block, String *buff);

void genBlockItems(Bean BlockItems, String *buff);

void genBlockItem(Bean BlockItem, String *buff);

void genIf(Bean If, String *buff);

void genIfElse(Bean IfElse, String *buff);

void genWhile(Bean While, String *buff);

int *genCond(Bean Cond, String *buff);

void genStmt(Bean Stmt, String *buff);

int *genArrayExps(Bean ArrayExps, String *buff);

String genLVal(Bean LVal, String *buff, bool io);

int *genExps(Bean Exp, String *buff);

int *genUnaryExp(Bean UnaryExp, String *buff);

void genUnaryExpFunc(Bean UnaryExp, String *buff);

int *genMulExp(Bean MulExp, String *buff);

int *genAddExp(Bean AddExp, String *buff);

int *genRelExp(Bean RelExp, String *buff);

int *genEqExp(Bean EqExp, String *buff);

int *genLAndExp(Bean LAndExp, String *buff);

int *genLOrExp(Bean LOrExp, String *buff);

String mystrcat(String *dst, String src);

String newString(size_t size);

String *newStringP();

void freeBuff(String *buff);

void errorPrint(String str);


#endif //COMPILESTUDY_GENLLVM_H