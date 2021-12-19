%{
#include "stdio.h"
#include "stdlib.h"
%}

/*常数*/
INT [1-9][0-9]*|[0]
FLOAT [0-9]*[.][0-9]+([eE][+-]?[0-9]*|[0])?f?
/*运算符*/
ASSIGNOP [=]
RELOP [>]|[<]|[>][=]|[<][=]|[=][=]|[!][=](^[=])
PLUS [+]
MINUS [-]
STAR [*]
DIV [/]
AND [&][&]
OR [|][|]
NOT [!]
/*界符*/
DOT [.]
SEMI [;]
COMMA [,]
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
/*keyword*/
MAIN main
BREAK break
CONST const
CONTINUE continue
WHILE while
DO do
FOR for
TYPE int|float|void
RETURN return
IF if
ELSE else
SPACE [ \n\t]
/*identifier*/
ID [a-zA-Z_][a-zA-Z_0-9]*
/*end of definition*/

%s COMMENT
%s COMMENT2
%%

<INITIAL>"//"			{BEGIN COMMENT;}
<COMMENT>\n				{BEGIN INITIAL;}
<COMMENT>.			 	{;}
<INITIAL>"/*"			{BEGIN COMMENT2;}
<COMMENT2>"*/"			{BEGIN INITIAL;}
<COMMENT2>.|\n			{;}

<INITIAL>{SEMI} {printf("semmi: %s\n", yytext);}

<INITIAL>{COMMA} {
    printf("comma: %s\n", yytext);
}
<INITIAL>{ASSIGNOP} {
    printf("assignop: %s\n", yytext);
}

<INITIAL>{INT} {
    printf("integer: %s\n", yytext);
}

<INITIAL>{FLOAT} {
    printf("float: %s\n", yytext);
}

<INITIAL>{PLUS} |
{MINUS} |
{DIV} |
{STAR} {
    printf("operator: %s\n", yytext);
}

<INITIAL>{RELOP} {
    printf("relop: %s\n", yytext);
}

<INITIAL>{AND} |
{OR} |
{NOT} {
    printf("logic operator: %s\n", yytext);
}

<INITIAL>{DOT} {
    printf("dot: %s\n", yytext);
}
<INITIAL>{RETURN} |
{IF} |
{ELSE} |
{WHILE} |
{FOR} |
{DO} |
{MAIN} |
{BREAK} |
{CONTINUE} {
    printf("keyword: %s\n", yytext);
}

<INITIAL>{TYPE} {
    printf("type: %s\n", yytext);
}

<INITIAL>{LP} |
{RP} |
{LB} |
{RB} |
{LC} |
{RC} {
    printf("brackets : %s\n", yytext);
}

<INITIAL>{SPACE} |
. {
/*ABANDON THESE CHARACTORS*/
}

<INITIAL>{ID} {
    printf("ID: %s\n", yytext);
}
%%
int yywrap() {
  return 1;
}

int main(int argc, char** argv) {
   if (argc > 1) {
       if (!(yyin = fopen(argv[1], "r"))) {
           perror(argv[1]);
           return 1;
       }
   }
   while (yylex());
   return 0;
}