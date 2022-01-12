//
// Created by JakoError on 2020/12/26.
//
#pragma once
#ifndef COMPILESTUDY_HASHMAP_H
#define COMPILESTUDY_HASHMAP_H

#include <stdbool.h>

typedef char *String;

#define KEY_TYPE String
#define VALUE_TYPE int**

#define DEFAULT_MAP_LENGTH 100

typedef struct hashmap *HashMap;
typedef struct node *HashNode;

typedef struct {
    KEY_TYPE key;
    VALUE_TYPE value;
} DataType;

struct node {
    DataType data;
    HashNode next;
};

struct hashmap {
    int size;
    struct node map[DEFAULT_MAP_LENGTH];
};

/**
 * 乘法hash算法，乘数为31（jdk8）
 * @param key --it should be string
 * @return hashcode of string-->abs
 */
int hash(char key[]);

/**
 * creat hashmap with existing keys and values
 * if key and value are null, the map will be empty
 * we allow keys or values are null
 *
 * when size is out of bound we have no idea to control it in C
 * @param keys format as string(i use strlen to do it)
 * @param values
 * @param size it is important to deal with size
 * @return hashmap
 */
HashMap createHashMap(KEY_TYPE keys[], VALUE_TYPE*values, int size);

//---增
bool putData(HashMap hm, KEY_TYPE key, VALUE_TYPE value);

bool putAllData(HashMap hm, KEY_TYPE key[], VALUE_TYPE value[], int size);

//---删
bool delete(HashMap hm, KEY_TYPE key);

//--查
VALUE_TYPE*getValue(HashMap hm, KEY_TYPE key);

DataType *getAllData(HashMap hm);

void clear(HashMap hm);

void freeHashMap(HashMap);

#endif //COMPILESTUDY_HASHMAP_H
