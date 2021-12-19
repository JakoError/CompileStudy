//
// Created by JakoError on 2021/12/15.
//

#ifndef FLEXSTUDY_LIST_H
#define FLEXSTUDY_LIST_H

#include "hashMap.h"

#define LIST_VALUE_TYPE HashMap
typedef struct list *List;
struct list {
    LIST_VALUE_TYPE element;
    List next;
};

List range;

List newList(List);

VALUE_TYPE getVarValue(KEY_TYPE key);

void exitRange();

#endif //FLEXSTUDY_LIST_H
