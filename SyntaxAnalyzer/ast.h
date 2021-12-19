//
// Created by JakoError on 2021/11/29.
//

#ifndef FLEXSTUDY_AST_H
#define FLEXSTUDY_AST_H

typedef char *String;

typedef struct bean *Bean;
struct bean {
    String type;
    String value;
    int i;
    Bean *beans;
};

Bean root;

void printAst(Bean bean, int layer);

Bean newBean();

Bean beanInfo(String type, String value);

void tobType(Bean bean, String type);

void tobValue(Bean bean, String value);

Bean *newBeans();

void addBean(Bean bean, Bean child);

void addBeans(Bean bean, Bean beans);

String toString(Bean bean);

int o_atoi(String str);

int h_atoi(String str);

String itos(int i);

#endif //FLEXSTUDY_AST_H
