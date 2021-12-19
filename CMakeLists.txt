cmake_minimum_required(VERSION 3.19)
project(FlexStudy C)

set(CMAKE_C_STANDARD 99)

add_executable(lex.yy LexicalAnalyzer/lex.yy.c)

add_executable(man_lex LexicalAnalyzer/man_lex.c)

add_executable(ast SyntaxAnalyzer/main.c SyntaxAnalyzer/ast.c SyntaxAnalyzer/ast.h)

add_executable(test1 BisonCodeGenerate/workout/test1.c BisonCodeGenerate/workout/ast.c BisonCodeGenerate/workout/ast.h)

add_executable(lrparser BisonCodeGenerate/workout/main.c
        BisonCodeGenerate/workout/lrparser.tab.c BisonCodeGenerate/workout/lrparser.tab.h
        BisonCodeGenerate/workout/ast.c BisonCodeGenerate/workout/ast.h
        BisonCodeGenerate/workout/lex.yy.c
        BisonCodeGenerate/workout/genllvm.c BisonCodeGenerate/workout/genllvm.h
        BisonCodeGenerate/workout/hashMap.c BisonCodeGenerate/workout/hashMap.h
        BisonCodeGenerate/workout/list.c BisonCodeGenerate/workout/list.h)

