//
// Created by JakoError on 2021/12/15.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

List newList(List next) {
    List t = (List) malloc(sizeof(struct list));
    if (t == NULL) {
        printf("error in malloc list\n");
        exit(0);
    }
    memset(t, 0, sizeof(struct list));
    t->next = next;
    t->element = createHashMap(NULL, NULL, 0);
    return t;
}

VALUE_TYPE getVarValue(KEY_TYPE key) {
    List r = range;
    VALUE_TYPE result;
    while (r != NULL) {
        VALUE_TYPE*value = getValue(r->element, key);
        if (value != NULL) {
            result = *value;
            break;
        }
        r = r->next;
    }
    if (r == NULL) {
        printf("Error:use of undeclared identifier '%s'\n", key);
        exit(0);
    }
    return result;
}

void exitRange() {
    if (range == NULL) return;
    List p = range;
    range = range->next;
    freeHashMap(p->element);
    free(p);
}
