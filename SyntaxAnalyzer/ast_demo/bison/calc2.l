%{
#include <stdlib.h>
void yyerror(char *);
#include "calc2.tab.h"
%}

%%

[0-9]+  {
			yylval = atoi(yytext);
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
