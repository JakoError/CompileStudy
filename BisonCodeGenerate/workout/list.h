//
// Created by JakoError on 2021/12/15.
//

#ifndef COMPILESTUDY_LIST_H
#define COMPILESTUDY_LIST_H

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

List exitRange(List list);

#endif //COMPILESTUDY_LIST_H
