%{
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "lrparser.tab.h"

%}


delim		[ \t\n]
ws			{delim}+
letter		[A-Za-z_]
digit		[0-9]
nonz_digit  [1-9]
o_digit     [0-7]
h_digit     [0-9a-fA-F]
id			{letter}({letter}|{digit})*
number		[0]|{nonz_digit}{digit}*
o_number    [0]{o_digit}+
h_number    [0][xX]{h_digit}+

/* 状态（条件）定义 */
%s COMMENT
%s COMMENT2
%%

<INITIAL>"//"			{BEGIN COMMENT;}
<COMMENT>\n				{BEGIN INITIAL;}
<COMMENT>.			 	{;}
<INITIAL>"/*"			{BEGIN COMMENT2;}
<COMMENT2>"*/"			{BEGIN INITIAL;}
<COMMENT2>.|\n			{;}


<INITIAL>{ws}	          {;}
<INITIAL>break			  {return BREAK;}
<INITIAL>const			  {return CONST;}
<INITIAL>continue		  {return CONTINUE;}
<INITIAL>do		          {return DO;}
<INITIAL>else			  {return ELSE;}
<INITIAL>for			  {return FOR;}
<INITIAL>if		          {return IF;}
<INITIAL>int			  {return INT;}
<INITIAL>main			  {return MAIN;}
<INITIAL>return			  {return RETURN;}
<INITIAL>void			  {return VOID;}
<INITIAL>while			  {return WHILE;}

<INITIAL>"+"	          {return *yytext;}
<INITIAL>"-"	          {return *yytext;}
<INITIAL>"*"	          {return *yytext;}
<INITIAL>"/"	          {return *yytext;}
<INITIAL>"%"	          {return *yytext;}
<INITIAL>"&&"	          {return AND;}
<INITIAL>"||"	          {return OR;}
<INITIAL>"="	          {return *yytext;}
<INITIAL>"=="	          {return EQU_CMP;}
<INITIAL>"!="	          {return NEQU_CMP;}
<INITIAL>"<"	          {return *yytext;}
<INITIAL>"<="	          {return LESE_CMP;}
<INITIAL>">"	          {return *yytext;}
<INITIAL>">="	          {return GREE_CMP;}

<INITIAL>"("	          {return *yytext;}
<INITIAL>")"	          {return *yytext;}
<INITIAL>"{"	          {return *yytext;}
<INITIAL>"}"	          {return *yytext;}
<INITIAL>"["	          {return *yytext;}
<INITIAL>"]"	          {return *yytext;}
<INITIAL>";"	          {return *yytext;}
<INITIAL>","	          {return *yytext;}

<INITIAL>{id}	          {yylval.sValue = (String) malloc(sizeof(char)* strlen(yytext));strcpy(yylval.sValue,yytext);return IDENT;}
<INITIAL>{number}	      {yylval.iValue = atoi(yytext);return INTCONST;}
<INITIAL>{o_number}    	  {yylval.iValue = o_atoi(yytext);return INTCONST;}
<INITIAL>{h_number}		  {yylval.iValue = h_atoi(yytext);return INTCONST;}

<INITIAL>.				  {printf("invalid character:%s",yytext);}

%%

int yywrap (){
  return 1;
}