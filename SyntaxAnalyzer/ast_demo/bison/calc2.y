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

expr: factor			  {$$ = $1;}
	| expr '+' factor     {$$ = $1 + $3;}
	| expr '-' factor     {$$ = $1 - $3;}
	;
	
factor: term
	| factor '*' term    {$$ = $1 * $3;} 
	| factor '/' term    {$$ = $1 / $3;}
	;
	
term: NUMBER            {$$ = $1;}
	| '-' term          {$$ = -$2; }
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
