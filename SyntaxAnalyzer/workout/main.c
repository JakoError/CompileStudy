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
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        return 0;
    root = beanInfo("root", NULL);
    printf("--start parse--\n");
    yyparse();
    printf("--end parse--\n");
    printAst(root, 0);

    if (argc > 2)
        genOut = fopen(argv[2], "w+");
    else {
        printf("please set the second argument\n");
        return 0;
    }
    if (genOut == NULL)
        printf("open file failed\n");


    range = newList(NULL);

    funcType = createHashMap(NULL, NULL, 0);
    funcPara = createHashMap(NULL, NULL, 0);

    fprintf(genOut, "; ModuleID = '%s'\n"
                    "source_filename = \"%s\"\n", argv[1], argv[1]);
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

    return 0;
}