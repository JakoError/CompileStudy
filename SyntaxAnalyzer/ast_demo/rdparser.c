/*
 ============================================================================
 Name        : rdparser.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum yytokentype {
	NUMBER = 258,
	EOL = 259
};


extern int yylex();
extern int yylval;
extern char* yytext;


int factor();
int expr();
int term();

int tok;


void advance()
{
	tok = yylex();
	printf("tok: %s\n", yytext);
}

//exp: factor
//	| exp '+' factor
//	| exp '-' factor
//	;

int expr()
{
	int l = factor();
	while(tok == '+' || tok == '-')
	{
		int oper = tok;
		advance();
		int r = factor();
		if( oper == '+')
			l += r;
		else
			l -= r;
	}
	return l;
}

//factor: term
//	| factor '*' term
//	| factor '/' term
//	;

int factor()
{
	int l = term();
	while(tok == '*' || tok == '/')
	{
		int oper = tok;
		advance();
		int r = term();
		if( oper == '*')
			l *= r;
		else
			l /= r;
	}
	return l;
}


//term: NUMBER
//	| '-' term
//	;

int term()
{
	if(tok == NUMBER)
	{
		advance();
		return yylval;
	}
	else if(tok == '-')
	{
		advance();
		int k = term();
		return -k;
	}
	else if(tok == 'q')
		exit(0);
	return -1;
}


typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	int ivalue;
	char* nodeType;
	past left;
	past right;
};

past newAstNode()
{
	past node = malloc(sizeof(ast));
	if(node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	return node;
}

past newNum(int value)
{
	past var = newAstNode();
	var->nodeType = "intValue";
	var->ivalue = value;
	return var;
}
past newExpr(int oper, past left,past right)
{
	past var = newAstNode();
	var->nodeType = "expr";
	var->ivalue = oper;
	var->left = left;
	var->right = right;
	return var;
}

past astTerm()
{
	if(tok == NUMBER)
	{
		past n = newNum(yylval);
		advance();
		return n;
	}
	else if(tok == '-')
	{
		advance();
		past k = astTerm();
		past n = newExpr('-', NULL, k);
		return n;
	}
	else if(tok == 'q')
		exit(0);
	return NULL;
}


past astFactor()
{
	past l = astTerm();
	while(tok == '*' || tok == '/')
	{
		int oper = tok;
		advance();
		past r = astTerm();
		l = newExpr(oper, l, r);
	}
	return l;
}

past astExpr()
{
	past l = astFactor();
	while(tok == '+' || tok == '-')
	{
		int oper = tok;
		advance();
		past r = astFactor();
		l = newExpr(oper, l, r);
	}
	return l;
}

void showAst(past node, int nest)
{
	if(node == NULL)
		return;

	int i = 0;
	for(i = 0; i < nest; i ++)
		printf("  ");
	if(strcmp(node->nodeType, "intValue") == 0)
		printf("%s %d\n", node->nodeType, node->ivalue);
	else if(strcmp(node->nodeType, "expr") == 0)
		printf("%s '%c'\n", node->nodeType, (char)node->ivalue);
	showAst(node->left, nest+1);
	showAst(node->right, nest+1);

}

int main(int argc, char **argv)
{
	while(1)
	{
		printf("input expression, 'q' to exit>");
		advance();
		int r = expr();
		printf("result: %d\n", r);

		//past rr = astExpr();
		//showAst(rr, 0);
	}
	return 0;
}
