# COMPILESTUDY
### flex and bison for SysY language
# A project for Compiling SysY Language.
## [definition of SysY](/Document/SysY语言定义.pdf)
> ## 1.**Lexical Analyzer**
> > ### generate token flow
> > - ![flex_example](/Document/flex_example.png)
> > - **[Flex/Lex](https://www.gnu.org/software/flex/)**
> > > - *[auto_lex.l](LexicalAnalyzer/auto_lex.l)*
> > > - *[lex.yy.c](LexicalAnalyzer/lex.yy.c)* (lex generate)
> >  - **manual c process**
> > > -  *[man_lex.c](LexicalAnalyzer/man_lex.c) [man_lex.h](LexicalAnalyzer/man_lex.h)*
> ## 2.**Syntax Analyzer**
> > ### generate abstract syntax tree
> > - ![ast_example](/Document/ast_example.png)
> > - **[Bison/Yacc](https://www.gnu.org/software/bison/) code**
> > > - *[lrparser.y](SyntaxAnalyzer/lrparser.y)*
> > > - *[main.c](SyntaxAnalyzer/main.c) [ast.c](SyntaxAnalyzer/ast.c) [ast.h](SyntaxAnalyzer/ast.h)*
> >  - **manual java process**
> > > - *[rdcheck.java](/SyntaxAnalyzer/SyntaxJava/rdcheck.java)* just check
> > > - *[rdparser.java](/SyntaxAnalyzer/SyntaxJava/rdparser.java)* generate ast
> ## 3.**intermidiate code generator and optimizor**
> > ### combine the semantic analyzer to it
> > - ![ll_example](/Document/ll_example.png)
> >  - **manual c process** generate .ll file
> > > - *[lrparser](BisonCodeGenerate/workout/) BisonCodeGenerate/workout/main.c
        BisonCodeGenerate/workout/lrparser.tab.c BisonCodeGenerate/workout/lrparser.tab.h
        BisonCodeGenerate/workout/ast.c BisonCodeGenerate/workout/ast.h
        BisonCodeGenerate/workout/lex.yy.c
        BisonCodeGenerate/workout/genllvm.c BisonCodeGenerate/workout/genllvm.h
        BisonCodeGenerate/workout/hashMap.c BisonCodeGenerate/workout/hashMap.h
        BisonCodeGenerate/workout/list.c BisonCodeGenerate/workout/list.h*
