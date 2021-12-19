%{

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

%}

%union{
	int			iValue;
	past		pAst;
};


%token <iValue> NUMBER
%type  <pAst>	program expr factor term

%%

program: program expr '\n'      { showAst($2, 0); }
		|
		;

expr: factor			  
	| expr '+' factor     {$$ = newExpr('+', $1, $3);}
	| expr '-' factor     {$$ = newExpr('-', $1, $3);}
	;
	
factor: term
	| factor '*' term    {$$ = newExpr('*', $1, $3);} 
	| factor '/' term    {$$ = newExpr('/', $1, $3);}
	;
	
term: NUMBER            {$$ = newNum($1);}
	| '-' term          {$$ = newExpr('-', NULL, $2); }
	;

%%

