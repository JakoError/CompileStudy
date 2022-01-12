import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class rdcheck {
    public static final String ID = "Ident";
    public static final String CONST = "const";
    public static final String INT = "int";
    public static final String INT_CONST = "IntConst";
    public static final String VOID = "void";
    public static final String IF = "if";
    public static final String IF_BODY = "if_body";
    public static final String ELSE = "else";
    public static final String ELSE_BODY = "else_body";
    public static final String WHILE = "while";
    public static final String WHILE_BODY = "while_body";
    public static final String BREAK = "break";
    public static final String CONTINUE = "continue";
    public static final String RETURN = "return";
    public static final String MAIN = "main";

    public static class Bean {
        public String type;
        public String value;
        public ArrayList<Bean> beans;

        public Bean() {
            beans = new ArrayList<>();
        }

        public Bean(String type) {
            this();
            this.type = type;
        }

        public Bean(String type, String value) {
            this();
            this.type = type;
            this.value = value;
        }

        public void add(Bean bean) {
            if (bean != null)
                beans.add(bean);
        }

        @Override
        public String toString() {
            if (value == null || value.trim().length() == 0)
                return type;
            return type + "(" + value + ")";
        }
    }

    public static BufferedReader reader;
    public static int index = 0;
    public static int length = 0;
    public static int max_sign = 0;
    public static ArrayList<String> type;
    public static ArrayList<String> value;
    public static Stack<Integer> sign;
    public static ArrayList<StackTraceElement> elements = new ArrayList<>();

    public static void mark() {
        sign.push(index);
    }

    public static Bean back() {
        index = sign.pop();
        //跟踪识别最后位置
        if (index > max_sign) {
            max_sign = index;
            elements = new ArrayList<>();
        }
        if (index >= max_sign) {
            elements.add(Thread.currentThread().getStackTrace()[2]);
        }
//        max_sign = Math.max(index, max_sign);
        return null;
    }

    public static void reset() {
        index = sign.peek();
    }

    public static boolean matchType(String type) {
        boolean match = index < rdcheck.type.size() && rdcheck.type.get(index).equals(type);
        //仅在匹配时增加（避免内部错失）
        //消费后才下一个
        if (match) index++;
        return match;
    }

    public static boolean matchValue(String value) {
        boolean match = index < rdcheck.value.size() && rdcheck.value.get(index).equals(value);
        if (match) index++;
        return match;
    }

    public static Bean toBean(int i) {
        if (i >= 0 && i < length) {
            return new Bean(type.get(i), value.get(i));
        }
        return null;
    }

    public static void main(String[] args) {
        //读取词法分析后的文件
        if (args.length >= 1) {
            File in = new File(args[0]);
            try {
                reader = new BufferedReader(new FileReader(in));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }
        //从lex分析后的文件中获取整个表
        type = new ArrayList<>();
        value = new ArrayList<>();
        sign = new Stack<>();
        do {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (line == null) break;
            if (line.trim().length() == 0) continue;
            String[] str = line.split(" ");
            type.add(str[0]);
            value.add(str[1]);
        } while (true);
        length = Math.min(type.size(), value.size());
        //开始检查
        while (index < length) {
            Bean compUnit = CompUnit();
            if (compUnit == null) {
                System.out.println("语法出错，最大位置为：line" + max_sign);
                System.out.println("对应内容：" + type.get(max_sign) + " " + value.get(max_sign));
                for (StackTraceElement element : elements) {
                    System.out.println(element);
                }
                System.exit(0);
//                index = max_sign + 1;
//                continue;
            }
        }
        System.out.println("检查结束");
    }

    public static Bean CompUnit() {
        Bean compUnit = new Bean("CompUnit");
        mark();
        Bean decl = Decl();
        if (decl != null) {
            compUnit.add(decl);
            Bean compUnit1 = CompUnit();
            if (compUnit1 != null)
                compUnit.add(compUnit1);
            sign.pop();
            return compUnit;
        }
        Bean funcDef = FuncDef();
        if (funcDef != null) {
            compUnit.add(funcDef);
            Bean compUnit1 = CompUnit();
            if (compUnit1 != null)
                compUnit.add(compUnit1);
            sign.pop();
            return compUnit;
        }
        return back();
    }

    public static Bean Decl() {
        Bean decl = new Bean("Decl");
        mark();
        Bean constDecl = ConstDecl();
        if (constDecl != null) {
            decl.add(constDecl);
            sign.pop();
            return decl;
        }
        Bean varDecl = VarDecl();
        if (varDecl != null) {
            decl.add(varDecl);
            sign.pop();
            return decl;
        }
        return back();
    }

    public static Bean ConstDecl() {
        Bean constDecl = new Bean("ConstDecl");
        mark();
        if (!matchValue(CONST)) return back();
        Bean bType = BType();
        if (bType == null) return back();
        constDecl.add(bType);
        Bean constDef = ConstDef();
        if (constDef == null) return back();
        constDecl.add(constDef);
        while (matchValue(",")) {
            constDef = ConstDef();
            if (constDef == null) return back();
            constDecl.add(constDef);
        }
        if (!matchValue(";")) return back();

        sign.pop();
        return constDecl;
    }

    public static Bean BType() {
        Bean bType = new Bean("BType");
        mark();
        if (!matchValue(INT)) return back();
        bType.value = INT;

        sign.pop();
        return bType;
    }

    public static Bean ConstDef() {
        Bean constDef = new Bean("ConstDef");
        mark();
        if (!matchType(ID)) return back();
        constDef.add(toBean(index - 1));
        while (matchValue("[")) {
            Bean constExp = ConstExp();
            if (constExp == null) return back();
            constDef.add(constExp);
            if (!matchValue("]")) return back();
        }
        if (!matchValue("=")) return back();
        Bean constInitVal = ConstInitVal();
        if (constInitVal == null) return back();
        constDef.add(constInitVal);

        sign.pop();
        return constDef;
    }

    public static Bean ConstInitVal() {
        Bean constInitVal = new Bean("ConstInitVal");
        mark();

        Bean constExp = ConstExp();
        if (constExp != null) {
            constInitVal.add(constExp);
            sign.pop();
            return constInitVal;
        }

        //force judge
        if (!matchValue("{")) return back();

        Bean constInitVal1 = ConstInitVal();
        //Optional
        if (constInitVal1 != null) {
            constInitVal.add(constInitVal1);
            while (matchValue(",")) {
                constInitVal1 = ConstInitVal();
                if (constInitVal1 == null) return back();
                constInitVal.add(constInitVal1);
            }
        }
        if (!matchValue("}")) return back();
        sign.pop();
        return constInitVal;
    }

    public static Bean VarDecl() {
        Bean varDecl = new Bean("VarDecl");
        mark();

        Bean bType = BType();
        if (bType == null) return back();
        varDecl.add(bType);

        Bean varDef = VarDef();
        if (varDef == null) return back();
        varDecl.add(varDef);

        while (matchValue(",")) {
            Bean varDef1 = VarDef();
            if (varDef1 == null) return back();
            varDecl.add(varDef1);
        }
        if (!matchValue(";")) return back();
        sign.pop();
        return varDecl;
    }

    public static Bean VarDef() {
        Bean varDef = new Bean("VarDef");
        mark();

        if (!matchType(ID)) return back();
        varDef.add(toBean(index - 1));
        while (matchValue("[")) {
            Bean constExp = ConstExp();
            if (constExp == null) return back();
            varDef.add(constExp);
            if (!matchValue("]")) return back();
        }

        //Optional
        if (matchValue("=")) {
            varDef.add(toBean(index - 1));
            Bean initVal = InitVal();
            if (initVal == null) return back();
            varDef.add(initVal);
        }
        sign.pop();
        return varDef;
    }

    public static Bean InitVal() {
        Bean initVal = new Bean("InitVal");
        mark();

        Bean exp = Exp();
        if (exp != null) {
            initVal.add(exp);
            sign.pop();
            return initVal;
        }

        if (!matchValue("{")) return back();
        Bean initVal1 = InitVal();
        //Optional
        if (initVal1 != null) {
            initVal.add(initVal1);
            while (matchValue(",")) {
                initVal1 = InitVal();
                if (initVal1 == null) return back();
                initVal.add(initVal1);
            }
        }
        if (!matchValue("}")) return back();
        sign.pop();
        return initVal;
    }

    public static Bean FuncDef() {
        Bean funcDef = new Bean("FuncDef");
        mark();

        Bean funcType = FuncType();
        if (funcType == null) return back();
        funcDef.add(funcType);

        if (!matchType(ID) && !matchValue(MAIN)) return back();
        funcDef.add(toBean(index - 1));

        if (!matchValue("(")) return back();
        //Optional
        Bean funcFParams = FuncFParams();
        if (funcFParams != null)
            funcDef.add(funcFParams);
        if (!matchValue(")")) return back();

        Bean block = Block();
        if (block == null) return back();
        funcDef.add(block);

        sign.pop();
        return funcDef;
    }

    public static Bean FuncType() {
        Bean funcType = new Bean("FuncType");
        mark();

        if (matchValue(VOID)) {
            funcType.value = VOID;
            sign.pop();
            return funcType;
        }
        if (matchValue(INT)) {
            funcType.value = INT;
            sign.pop();
            return funcType;
        }
        return back();
    }

    public static Bean FuncFParams() {
        Bean funcFParams = new Bean("FuncFParams");
        mark();

        Bean funcFParam = FuncFParam();
        if (funcFParam == null) return back();
        funcFParams.add(funcFParam);
        while (matchValue(",")) {
            funcFParam = FuncFParam();
            if (funcFParam == null) return back();
            funcFParams.add(funcFParam);
        }
        sign.pop();
        return funcFParams;
    }

    public static Bean FuncFParam() {
        Bean funcFParam = new Bean("FuncFParam");
        mark();

        Bean bType = BType();
        if (bType == null) return back();
        funcFParam.add(bType);

        if (!matchType(ID)) return back();
        funcFParam.add(toBean(index - 1));
        if (matchValue("[") && matchValue("]"))
            while (matchValue("[")) {
                Bean exp = Exp();
                if (exp == null) return back();
                funcFParam.add(exp);
                if (!matchValue("]")) return back();
            }
        sign.pop();
        return funcFParam;
    }

    public static Bean Block() {
        Bean block = new Bean("Block");
        mark();

        if (!matchValue("{")) return back();
        Bean blockItem;
        while ((blockItem = BlockItem()) != null)
            block.add(blockItem);
        if (!matchValue("}")) return back();
        sign.pop();
        return block;
    }

    public static Bean BlockItem() {
        Bean blockItem = new Bean("BlockItem");
        mark();

        Bean decl = Decl();
        if (decl != null) {
            blockItem.add(decl);
            sign.pop();
            return blockItem;
        }
        Bean stmt = Stmt();
        if (stmt != null) {
            blockItem.add(stmt);
            sign.pop();
            return blockItem;
        }
        return back();
    }

    public static Bean Stmt() {
        Bean stmt = new Bean("Stmt");
        mark();

        if (matchValue(";")) return stmt;

        Bean lVal = LVal();
        if (lVal != null) {
            stmt.add(lVal);
            if (matchValue("=")) {
                stmt.add(toBean(index - 1));
                Bean exp = Exp();
                if (exp != null) {
                    stmt.add(exp);
                    if (matchValue(";")) {
                        sign.pop();
                        return stmt;
                    }
                }
            }
        }
        reset();
        stmt.beans.clear();

        Bean exp = Exp();
        //Optional
        if (exp != null) {
            stmt.add(exp);
            if (matchValue(";")) {
                sign.pop();
                return stmt;
            }
        }
        reset();
        stmt.beans.clear();

        Bean block = Block();
        if (block != null) {
            stmt.add(block);
            sign.pop();
            return stmt;
        }
        reset();
        stmt.beans.clear();

        if (matchValue(IF)) {
            stmt.value = IF;

            if (!matchValue("(")) return back();
            Bean cond = Cond();
            if (cond == null) return back();
            stmt.add(cond);
            if (!matchValue(")")) return back();
            Bean stmt1 = Stmt();
            if (stmt1 == null) return back();
            stmt1.value = IF_BODY;
            stmt.add(stmt1);

            if (matchValue(ELSE)) {
                Bean stmt2 = Stmt();
                if (stmt2 == null) return back();
                stmt2.value = ELSE_BODY;
                stmt.add(stmt2);
            }
            sign.pop();
            return stmt;
        }

        if (matchValue(WHILE)) {
            stmt.value = WHILE;

            if (!matchValue("(")) return back();
            Bean cond = Cond();
            if (cond == null) return back();
            stmt.add(cond);
            if (!matchValue(")")) return back();
            Bean stmt1 = Stmt();
            if (stmt1 == null) return back();
            stmt1.value = WHILE_BODY;
            stmt.add(stmt1);
            sign.pop();
            return stmt;
        }

        if (matchValue(BREAK)) {
            stmt.value = BREAK;
            if (!matchValue(";")) return back();
            sign.pop();
            return stmt;
        }

        if (matchValue(CONTINUE)) {
            stmt.value = CONTINUE;
            if (!matchValue(";")) return back();
            sign.pop();
            return stmt;
        }

        if (matchValue(RETURN)) {
            stmt.value = RETURN;
            Bean exp1 = Exp();
            if (exp1 != null)
                stmt.add(exp1);
            if (!matchValue(";")) return back();
            sign.pop();
            return stmt;
        }

        return back();
    }

    public static Bean Exp() {
        Bean exp = new Bean("Exp");
        mark();

        Bean addExp = AddExp();
        if (addExp == null) return back();
        exp.add(addExp);
        sign.pop();
        return exp;
    }

    public static Bean Cond() {
        Bean cond = new Bean("Cond");
        mark();

        Bean lOrExp = LOrExp();
        if (lOrExp == null) return back();
        cond.add(lOrExp);
        sign.pop();
        return cond;
    }

    public static Bean LVal() {
        Bean lVal = new Bean("LVal");
        mark();

        if (!matchType(ID)) return back();
        lVal.add(toBean(index - 1));
        while (matchValue("[")) {
            Bean exp = Exp();
            if (exp == null) back();
            lVal.add(exp);
            if (!matchValue("]")) return back();
        }
        sign.pop();
        return lVal;
    }

    public static Bean PrimaryExp() {
        Bean primaryExp = new Bean("PrimaryExp");
        mark();

        if (matchValue("(")) {
            Bean exp = Exp();
            if (exp == null) return back();
            primaryExp.add(exp);
            if (!matchValue(")")) return back();
            sign.pop();
            return primaryExp;
        }

        Bean lVal = LVal();
        if (lVal != null) {
            primaryExp.add(lVal);
            sign.pop();
            return primaryExp;
        }

        Bean number = Number();
        if (number != null) {
            primaryExp.add(number);
            sign.pop();
            return primaryExp;
        }

        return back();
    }

    public static Bean Number() {
        Bean number = new Bean("Number");
        mark();

        if (!matchType(INT_CONST)) return back();
        number.add(toBean(index - 1));
        sign.pop();
        return number;
    }

    public static Bean UnaryExp() {
        Bean unaryExp = new Bean("UnaryExp");
        mark();

        if (matchType(ID)) {
            unaryExp.add(toBean(index - 1));
            if (matchValue("(")) {
                Bean funcRParams = FuncRParams();
                //Optional
                if (funcRParams != null)
                    unaryExp.add(funcRParams);
                if (matchValue(")")) {
                    sign.pop();
                    return unaryExp;
                }
            }
        }
        reset();
        unaryExp.beans.clear();

        Bean primaryExp = PrimaryExp();
        if (primaryExp != null) {
            unaryExp.add(primaryExp);
            sign.pop();
            return unaryExp;
        }

        Bean unaryOp = UnaryOp();
        if (unaryOp != null) {
            unaryExp.add(unaryOp);
            Bean unaryExp1 = UnaryExp();
            if (unaryExp1 == null) return back();
            unaryExp.add(unaryExp1);
            sign.pop();
            return unaryExp;
        }

        return back();
    }

    public static Bean UnaryOp() {
        Bean unaryOp = new Bean("UnaryOp");
        mark();

        if (matchValue("+")) {
            unaryOp.value = "+";
            sign.pop();
            return unaryOp;
        }
        if (matchValue("-")) {
            unaryOp.value = "-";
            sign.pop();
            return unaryOp;
        }
        if (matchValue("!")) {
            unaryOp.value = "!";
            sign.pop();
            return unaryOp;
        }
        return back();
    }

    public static Bean FuncRParams() {
        Bean funcRParams = new Bean("FuncRParams");
        mark();

        Bean exp = Exp();
        if (exp == null) return back();
        funcRParams.add(exp);

        while (matchValue(",")) {
            exp = Exp();
            if (exp == null) return back();
            funcRParams.add(exp);
        }

        sign.pop();
        return funcRParams;
    }

    public static Bean MulExp() {
        Bean mulExp = new Bean("MulExp");
        mark();

        Bean unaryExp = UnaryExp();
        if (unaryExp == null) return back();
        mulExp.add(unaryExp);

        while (matchValue("*") || matchValue("/") || matchValue("%")) {
            mulExp.add(toBean(index - 1));
            Bean mulExp1 = MulExp();
            if (mulExp1 == null) return back();
            mulExp.add(mulExp1);
        }

        sign.pop();
        return mulExp;
    }

    public static Bean AddExp() {
        Bean addExp = new Bean("AddExp");
        mark();

        Bean mulExp = MulExp();
        if (mulExp == null) return back();
        addExp.add(mulExp);

        while (matchValue("+") || matchValue("-")) {
            addExp.add(toBean(index - 1));
            Bean addExp1 = AddExp();
            if (addExp1 == null) return back();
            addExp.add(addExp1);
        }

        sign.pop();
        return addExp;
    }

    public static Bean RelExp() {
        Bean relExp = new Bean("RelExp");
        mark();

        Bean addExp = AddExp();
        if (addExp == null) return back();
        relExp.add(addExp);

        while (matchValue("<") || matchValue(">") || matchValue("<=") || matchValue(">=")) {
            relExp.add(toBean(index - 1));
            Bean relExp1 = RelExp();
            if (relExp1 == null) return back();
            relExp.add(relExp1);
        }

        sign.pop();
        return relExp;
    }

    public static Bean EqExp() {
        Bean eqExp = new Bean("EqExp");
        mark();

        Bean relExp = RelExp();
        if (relExp == null) return back();
        eqExp.add(relExp);

        while (matchValue("==") || matchValue("!=")) {
            eqExp.add(toBean(index - 1));
            Bean eqExp1 = EqExp();
            if (eqExp1 == null) return back();
            eqExp.add(eqExp1);
        }

        sign.pop();
        return eqExp;
    }

    public static Bean LAndExp() {
        Bean lAndExp = new Bean("LAndExp");
        mark();

        Bean eqExp = EqExp();
        if (eqExp == null) return back();
        lAndExp.add(eqExp);

        while (matchValue("&&")) {
            lAndExp.add(toBean(index - 1));
            Bean lAndExp1 = LAndExp();
            if (lAndExp1 == null) return back();
            lAndExp.add(lAndExp1);
        }

        sign.pop();
        return lAndExp;
    }

    public static Bean LOrExp() {
        Bean lOrExp = new Bean("LOrExp");
        mark();

        Bean lAndExp = LAndExp();
        if (lAndExp == null) return back();
        lOrExp.add(lAndExp);

        while (matchValue("||")) {
            lOrExp.add(toBean(index - 1));
            Bean lOrExp1 = LOrExp();
            if (lOrExp1 == null) return back();
            lOrExp.add(lOrExp1);
        }

        sign.pop();
        return lOrExp;
    }

    public static Bean ConstExp() {
        Bean constExp = new Bean("ConstExp");
        mark();

        Bean addExp = AddExp();
        if (addExp == null) return back();
        constExp.add(addExp);

        sign.pop();
        return constExp;
    }
}