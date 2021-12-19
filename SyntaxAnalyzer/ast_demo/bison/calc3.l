%{
#include <stdlib.h>
#include "ast.h"
#include "calc3.tab.h"

void yyerror(char *);
%}

%%

[0-9]+  {
			yylval.iValue = atoi(yytext);
			return NUMBER;
		}
		
[-+*/\n] 		return *yytext;
[ \t] ; 	/* skip whitespace */
. yyerror("invalid character");

%%

int yywrap(void) 
{
	return 1;
}
