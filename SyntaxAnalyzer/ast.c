//
// Created by JakoError on 2021/11/29.
//

#include "ast.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printAst(Bean bean, int layer) {
    if (bean == NULL) return;

    printf("%s\n", toString(bean));
    if (bean->i > 0 && bean->beans != NULL) {
        for (int i = 0; i < bean->i; ++i) {
            for (int j = 0; j < layer; ++j)
                printf(" | ");
            printf(" |-");
            printAst(bean->beans[i], layer + 1);
        }
    }
}

Bean newBean() {
    Bean bean = (Bean) malloc(sizeof(struct bean));
    if (bean == NULL) {
        printf("error in malloc bean\n");
        exit(0);
    }
    memset(bean, 0, sizeof(struct bean));
    return bean;
}

Bean beanInfo(String type, String value) {
    Bean bean = newBean();
    bean->type = type;
    bean->value = value;
    return bean;
}

void tobType(Bean bean, String type) {
    if (bean == NULL) return;
    bean->type = type;
}

void tobValue(Bean bean, String value) {
    if (bean == NULL) return;
    bean->value = value;
}

Bean *newBeans() {
    Bean *beans = (Bean *) malloc(sizeof(Bean));
    if (beans == NULL) {
        printf("error in malloc bean\n");
        exit(0);
    }
    memset(beans, 0, sizeof(Bean));
    return beans;
}

void addBean(Bean bean, Bean child) {
    if (child == NULL) return;
    if (bean->beans == NULL) {
        bean->i = 0;
        bean->beans = newBeans();
    } else {
        bean->beans = realloc(bean->beans, sizeof(Bean) * (bean->i + 1));
        if (bean->beans == NULL) {
            printf("fail to realloc bean");
            exit(0);
        }
    }
    bean->beans[bean->i++] = child;
}

void addBeans(Bean bean, Bean beans) {
    if (bean == NULL || beans == NULL || beans->beans == NULL) return;
    for (int i = 0; i < beans->i; ++i)
        addBean(bean, beans->beans[i]);
    free(beans);
}

String toString(Bean bean) {
    if (bean->value == NULL || strlen(bean->value) == 0)
        return bean->type;
    String result = (String) malloc(sizeof(char) * (strlen(bean->type) + strlen(bean->value) + 3));
    sprintf(result, "%s(%s)", bean->type, bean->value);
    return result;
}

int o_atoi(String str) {
    if (str == NULL || strlen(str) < 1 || str[0] != '0') return 0;
    int len = strlen(str);
    int result = 0;
    int factor = 1;
    for (int i = 0; i < len - 1; ++i) {
        char c = str[len - i - 1];
        if (c < '0' || c > '7')
            return 0;
        result += (c - '0') * factor;
        factor *= 8;
    }
    return result;
}

int h_atoi(String str) {
    if (str == NULL || strlen(str) < 2 || (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))) return 0;
    int len = strlen(str);
    int result = 0;
    int factor = 1;
    for (int i = 0; i < len - 2; ++i) {
        char c = str[len - i - 1];
        if (c >= '0' && c <= '9')
            result += (c - '0') * factor;
        else if (c >= 'a' && c <= 'f')
            result += (c - 'a' + 10) * factor;
        else if (c >= 'A' && c <= 'F')
            result += (c - 'A' + 10) * factor;
        else
            return 0;

        factor *= 16;
    }
    return result;
}

String itos(int i) {
    String str = (String) malloc(sizeof(char) * 12);
    sprintf(str, "%d", i);
    return str;
}