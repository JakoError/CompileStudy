#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ast.h"
#include "list.h"
#include "genllvm.h"

#pragma warning(disable:4996)

extern FILE *yyin;

extern int yyparse(void);

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            printf("open fail errno = %d reason %s\n", errno, strerror(errno));
            printf("input from console(flex and bison won't work finely)exit\n");
            return 0;
        }
    } else {
        printf("please set the first argument .sy filepath\n");
        return 0;
    }
    root = beanInfo("root", NULL);
    printf("--start parse--\n");
    yyparse();
    printf("--end parse--\n");
    printf("--ast start--\n");
    printAst(root, 0);
    printf("--ast end--\n");

    if (argc > 2)
        genOut = fopen(argv[2], "w+");
    else {
        printf("please set the second argument .ll filepathn");
        return 0;
    }

    if (genOut == NULL) {
        printf("open fail errno = %d reason %s\n", errno, strerror(errno));
    } else {
        printf("result .ll file path:%s\n", argv[2]);
    }

    String *file_name = newStringP();
    char *p = argv[1] + strlen(argv[1]);
    while (p != argv[1] && *p != '\\') p--;
    if (p != argv[1]) p++;
    mystrcat(file_name, p);

    printf("--generate start--\n");

    range = newList(NULL);

    funcType = createHashMap(NULL, NULL, 0);
    funcPara = createHashMap(NULL, NULL, 0);

    fprintf(genOut, "; ModuleID = '%s'\n"
                    "source_filename = \"%s\"\n", *file_name, *file_name);
    fprintf(genOut, "target datalayout = \"e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128\"\n"
                    "target triple = \"x86_64-pc-windows-msvc19.29.30038\"\n\n"
                    "; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly\n"
                    "declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #1\n\n");
    fflush(genOut);
    for (int i = 0; i < root->i; ++i) {
        genCompUnit(root->beans[i], NULL);
        fflush(genOut);
    }

    fprintf(genOut,
            "\nattributes #0 = { noinline nounwind optnone uwtable \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"none\" \"less-precise-fpmad\"=\"false\" \"min-legal-vector-width\"=\"0\" \"no-infs-fp-math\"=\"false\" \"no-jump-tables\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n"
            "attributes #1 = { argmemonly nofree nosync nounwind willreturn writeonly }\n");
    fflush(genOut);

    printf("--generate finish--\n");
    return 0;
}