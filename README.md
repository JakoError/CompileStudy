# COMPILESTUDY
### flex and bison for SysY language
# A project for Compiling SysY Language.
> ## 1.**Lexical Analyzer**
> > ### generate token flow
> > - ![flex_example](/Document/flex_example.png)
> > - **Flex/lex**
> > > - *LexicalAnalyzer/auto_lex.l*
> > > - *LexicalAnalyzer/lex.yy.c* (lex generate)
> >  - **manual c process**
> > > -  *LexicalAnalyzer/man_lex.c(.h)*
> ## 2.**Syntax Analyzer**
> > ### generate abstract syntax tree
> > - ![ast_example](/Document/ast_example.png)
> > - **Bison/Yacc code**
> > > - *SyntaxAnalyzer/lrparser.y*
> > > - *SyntaxAnalyzer/main.c SyntaxAnalyzer/ast.c SyntaxAnalyzer/ast.h*
> >  - **manual java process**
> > > - *SyntaxAnalyzer/rdcheck.java* just check
> > > - *SyntaxAnalyzer/rdparser.java* generate ast
> ## 3.**intermidiate code generator and optimizor**
> > ### combine the semantic analyzer to it
> > - ![ll_example](/Document/ll_example.png)
> >  - **manual c process** generate .ll file
> > > - *lrparser BisonCodeGenerate/workout/main.c
        BisonCodeGenerate/workout/lrparser.tab.c BisonCodeGenerate/workout/lrparser.tab.h
        BisonCodeGenerate/workout/ast.c BisonCodeGenerate/workout/ast.h
        BisonCodeGenerate/workout/lex.yy.c
        BisonCodeGenerate/workout/genllvm.c BisonCodeGenerate/workout/genllvm.h
        BisonCodeGenerate/workout/hashMap.c BisonCodeGenerate/workout/hashMap.h
        BisonCodeGenerate/workout/list.c BisonCodeGenerate/workout/list.h*
