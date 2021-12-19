%{

#include <stdio.h>
#include <stdlib.h>
#define LT					1
#define	LE					2
#define GT					3
#define	GE					4
#define	EQ					5
#define NE					6
#define LLK                 7
#define RLK                 8
#define LBK                 9
#define RBK                 10
#define EQU                 11
#define SEM                 12

#define BREAK 				15
#define CONST 				16
#define CONTINUE 			17
#define DO 					18
#define ELSE 				19
#define FOR 				20
#define IF 					21
#define INT 				22
#define MAIN 				23
#define RETURN 				24
#define VOID 				25
#define WHILE 				26

#define ID                  40
#define NUMBER              41
#define OPERATOR            42
#define BOUND            	43
#define ERRORCHAR           44

#define NEWLINE             50

#define ADD                 61
#define DEC                 62
#define MUL                	63
#define DIV                 64


%}

 
delim		[ \t\n]
ws			{delim}+
letter		[A-Za-z_]
digit		[0-9]
id			{letter}({letter}|{digit})*
number		{digit}+

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
<INITIAL>break			  {return (BREAK);}
<INITIAL>const			  {return (CONST);}
<INITIAL>continue		  {return (CONTINUE);}
<INITIAL>do		          {return (DO);}
<INITIAL>else			  {return (ELSE);}
<INITIAL>for			  {return (FOR);}
<INITIAL>if		          {return (IF);}
<INITIAL>int			  {return (INT);}
<INITIAL>main			  {return (MAIN);}
<INITIAL>return			  {return (RETURN);}
<INITIAL>void			  {return (VOID);}
<INITIAL>while			  {return (WHILE);}

<INITIAL>{id}	          {return (ID);}
<INITIAL>{number}	      {return (NUMBER);}

<INITIAL>"+"	          {return (OPERATOR);}
<INITIAL>"-"	          {return (OPERATOR);}
<INITIAL>"*"	          {return (OPERATOR);}
<INITIAL>"/"	          {return (OPERATOR);}
<INITIAL>"%"	          {return (OPERATOR);}
<INITIAL>"&&"	          {return (OPERATOR);}
<INITIAL>"||"	          {return (OPERATOR);}
<INITIAL>"="	          {return (OPERATOR);}
<INITIAL>"=="	          {return (OPERATOR);}
<INITIAL>"!="	          {return (OPERATOR);}
<INITIAL>"<"	          {return (OPERATOR);}
<INITIAL>"<="	          {return (OPERATOR);}
<INITIAL>">"	          {return (OPERATOR);}
<INITIAL>">="	          {return (OPERATOR);}

<INITIAL>"<"	          {return (BOUND);}
<INITIAL>">"	          {return (BOUND);}
<INITIAL>"("	          {return (BOUND);}
<INITIAL>")"	          {return (BOUND);}
<INITIAL>"{"	          {return (BOUND);}
<INITIAL>"}"	          {return (BOUND);}
<INITIAL>"["	          {return (BOUND);}
<INITIAL>"]"	          {return (BOUND);}
<INITIAL>";"	          {return (BOUND);}
<INITIAL>","	          {return (BOUND);}

<INITIAL>.				  {return ERRORCHAR;}

 
%%

int yywrap (){
  return 1;
}

void writeout(int c){
  switch(c){
  	case ERRORCHAR: fprintf(yyout, "(ERRORCHAR, \"%s\")\t", yytext);break;
  	case BOUND: fprintf(yyout, "(BOUND, \"%s\")\t", yytext);break;  	  
  	case OPERATOR: fprintf(yyout, "(OPERATOR, \"%s\")\t", yytext);break;  	  
    
	case BREAK: fprintf(yyout, "(BREAK, \"%s\")\t", yytext);break;
    case CONST: fprintf(yyout, "(CONST, \"%s\")\t", yytext);break;
    case CONTINUE: fprintf(yyout, "(CONTINUE, \"%s\")\t", yytext);break;
    case DO: fprintf(yyout, "(DO, \"%s\")\t", yytext);break;
    case ELSE: fprintf(yyout, "(ELSE, \"%s\")\t", yytext);break;
    case FOR: fprintf(yyout, "(FOR, \"%s\")\t", yytext);break;
    case IF: fprintf(yyout, "(IF, \"%s\")\t", yytext);break;
    case INT: fprintf(yyout, "(INT, \"%s\")\t", yytext);break;
    case MAIN: fprintf(yyout, "(MAIN, \"%s\")\t", yytext);break;
    case RETURN: fprintf(yyout, "(RETURN, \"%s\")\t", yytext);break;
    case VOID: fprintf(yyout, "(VOID, \"%s\")\t", yytext);break;
    case WHILE: fprintf(yyout, "(WHILE, \"%s\")\t", yytext);break;
    
	case NUMBER: fprintf(yyout, "(NUM, \"%s\")\t", yytext);break;
    case ID: fprintf(yyout, "(ID, \"%s\")\t", yytext);break;
    case NEWLINE: fprintf(yyout, "\n");break;
    default:break;
  }
  return;
}


int main (int argc, char ** argv){
	int c,j=0;
	if (argc>=2){
	  if ((yyin = fopen(argv[1], "r")) == NULL){
	    printf("Can't open file %s\n", argv[1]);
	    return 1;
	  }
	  if (argc>=3){
	    yyout=fopen(argv[2], "w");
	  }
	}

	while (c = yylex()){
		writeout(c);
		j++;
		if (j%5 == 0)
			writeout(NEWLINE);
	}

	if(argc>=2){
		fclose(yyin);
		if (argc>=3) 
			fclose(yyout);
	}
	return 0;
}