#pragma warning (disable:4819)
//
// Created by JakoError on 2020/12/26.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "hashMap.h"


int hash(char key[]) {
    int hash = 0;
    if (key != NULL)//null 返回0
        for (int i = 0; i < strlen(key); ++i)
            hash = 31 * hash + key[i];
    return abs(hash);//非负
}

HashMap createHashMap(KEY_TYPE keys[], VALUE_TYPE values[], int size) {
    if (keys == NULL && values == NULL && size != 0) {
        printf("\nFAILED TO CREAT MAP:SIZE is not equal to 0 when Keys and Value are null\n");
        return NULL;
    }
    //----------------------------------------------------------预处理
    HashMap hm = (HashMap) malloc(sizeof(struct hashmap));
    if (hm == NULL) {
        printf("error in malloc HashMap\n");
        exit(0);
    }

    clear(hm);

    if (!size)
        return hm;

    //-----------------------------------------------------------插入值
    //插入所有值
    if (!putAllData(hm, keys, values, size))
        return NULL;

    return hm;
}

HashNode newNode() {
    HashNode pNode = malloc(sizeof(struct node));
    if (pNode == NULL) {
        printf("error in malloc HashNode\n");
        exit(0);
    }
    memset(pNode, 0, sizeof(struct node));
    return pNode;
}

bool putData(HashMap hm, KEY_TYPE key, VALUE_TYPE value) {
    if (hm == NULL || key == NULL)
        return false;
    int index = hash(key) % DEFAULT_MAP_LENGTH;
    HashNode p = &(hm->map[index]);

    while (!(p->data.key == NULL || strcmp(p->data.key, key) == 0 || p->next == NULL)) {
        p = p->next;
    }

    //不允许复写
    if(p->data.key!=NULL) return false;

    p->data.key = malloc(sizeof(key));
    strcpy(p->data.key, key);
    p->data.value = value;

    //prepare for next(mainly to avoid jump to NULL)
    p->next = newNode();

    hm->size++;
    return true;
}

bool putAllData(HashMap hm, KEY_TYPE key[], VALUE_TYPE value[], int size) {
    int ok = 0;
    for (int i = 0; i < size; ++i) {
        if (putData(hm, key[i], value[i]))
            ok++;
    }
    printf("\n填装%d个数据：成功%d个\n", size, ok);
    return ok == size;
}

//不想写了，我这用不到
bool delete(HashMap hm, KEY_TYPE key);

VALUE_TYPE *getValue(HashMap hm, KEY_TYPE key) {
    int index = hash(key) % DEFAULT_MAP_LENGTH;
    HashNode p = &hm->map[index];
    if (p->next == NULL)
        return NULL;
    if (p->next->next != NULL)
        while (strcmp(p->data.key, key) != 0) {
            p = p->next;
            if (p == NULL)
                return NULL;
        }
    return &p->data.value;
}

DataType *getAllData(HashMap hm) {
    static DataType list[100];
    DataType *l = list;
    for (int i = 0; i < DEFAULT_MAP_LENGTH; ++i) {
        HashNode p = &hm->map[i];
        if (p->next == NULL)
            continue;
        while (p->next != NULL) *(l++) = p->data;
    }
    return list;
}

void clear(HashMap hm) {
    memset(hm, 0, sizeof(struct hashmap));
    hm->size = 0;
}

void freeHashMap(HashMap hm) {
    if (hm == NULL) return;
    for (int i = 0; i < DEFAULT_MAP_LENGTH; ++i) {
        HashNode p = hm->map[i].next;
        while (p != NULL) {
            HashNode temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(hm);
}

