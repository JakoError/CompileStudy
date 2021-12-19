//
// Created by JakoError on 2021/10/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ast.h"

#pragma warning(disable:4996)

String mystrcat(String *dst, String src) {
    if (dst == NULL) return NULL;
    if (src == NULL || strlen(src) == 0) return *dst;
    int r;
    if (*dst == NULL) {
        *dst = malloc(sizeof(char) * (strlen(src) + 100));
        r = 0;
    } else {
        *dst = realloc(*dst, sizeof(char) * (strlen(*dst) + strlen(src) + 100));
        r = (int) strlen(*dst);
    }

    for (int i = 0; i < strlen(src); ++i)
        (*dst)[r++] = src[i];
    (*dst)[r] = '\0';
    return *dst;
}

int main() {
    String str = malloc(1000);
    strcpy(str, "1122296vgp34uh8npppppppppppppppppqpppppppppppu-quvg9608tq37-v4908tj-q34vt33");
    String *p = malloc(0);
//    *p = NULL;
//    mystrcat(p,
//             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaavv9834qphnu5tqqqqqqqqqqqqqqqqqqqqqqqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqtqnqqqqqqqqqqqqqqqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqnqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
//    printf("%s", *p);
//    free(*p);
//    free(p);
    return 0;
}