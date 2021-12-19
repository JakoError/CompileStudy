cmake_minimum_required(VERSION 3.19)
project(FlexStudy C)

set(CMAKE_C_STANDARD 99)

add_executable(main_lex main_lex.c main_lex.h)
add_executable(test test.c)
add_executable(man_lex LexicalAnalyzer/man_lex.c)

add_executable(rdparser SyntaxAnalyzer/rdparser.c)

add_executable(ast SyntaxAnalyzer/workout/ast.c SyntaxAnalyzer/workout/ast.h)
add_executable(test1 SyntaxAnalyzer/workout/test1.c SyntaxAnalyzer/workout/ast.c SyntaxAnalyzer/workout/ast.h)

add_executable(lrparser SyntaxAnalyzer/workout/main.c
        SyntaxAnalyzer/workout/lrparser.tab.c SyntaxAnalyzer/workout/lrparser.tab.h
        SyntaxAnalyzer/workout/ast.c SyntaxAnalyzer/workout/ast.h
        SyntaxAnalyzer/workout/lex.yy.c
        SyntaxAnalyzer/workout/genllvm.c SyntaxAnalyzer/workout/genllvm.h
        SyntaxAnalyzer/workout/hashMap.c SyntaxAnalyzer/workout/hashMap.h
        SyntaxAnalyzer/workout/list.c SyntaxAnalyzer/workout/list.h)

add_executable(lex.yy LexicalAnalyzer/lex.yy.c)