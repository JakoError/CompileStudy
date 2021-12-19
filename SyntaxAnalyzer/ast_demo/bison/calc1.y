%{

#include <stdio.h>
int yylex(void);
void yyerror(char *);

%}

%token NUMBER

%%

program: program expr '\n'      { printf("%d\n",  $2); }
		|
		;
expr:   NUMBER				{ $$ = $1; }
		| expr '+' NUMBER		{ $$ = $1 + $3; }
		| expr '-' NUMBER     	{ $$ = $1 - $3; }
		;

%%
void yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
}
int main(void) 
{
    yyparse();
    return 0;
}
