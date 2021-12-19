#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ast.h"

#pragma warning(disable:4996)

extern FILE *yyin;
extern int yyparse(void);

int main(int argc,char **argv) {
    if(argc > 1)
        yyin = fopen(argv[1],"r");
    else
        return 0;
    root = beanInfo("root",NULL);
    printf("--start parse--\n");
    yyparse();
    printf("--end parse--\n");
    printAst(root,0);
    return 0;
}