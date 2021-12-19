//
// Created by JakoError on 2021/10/17.
//

#include "man_lex.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * 每个被单独分出来的词
 * @param kind 符合Token中的kind(index)
 * @param value word值
 */
struct Word {
    int kind;
    char *value;
};
__attribute__((unused)) struct Word **words;//words动态分配大小(本程序并没有使用)
__attribute__((unused)) int wordsLayer = 0;
__attribute__((unused)) int wordsi = 0;

/**
 * 0-标识符 identifier
 * 1-基本字 keyword
 * 2-常数 const
 * 3-运算符 operator
 * 4-界符 bounds
 */
struct Token {
    int kind;
    char *name;
} tokens[6];

/**
 * 基于o的对target判断是否相同方法，o中并不完全相等，而是判断o是不是以target开头
 * @param o 需要进行判断的字符串
 * @param target 比较的特定字符串
 * @return true-- length of target  false-- -1 null-- 0
 */
int isPrefix(char *o, const char *target) {
    if (o == NULL || target == NULL)
        return 0;
    int i = 0;
    do {
        if (o[i] != target[i])
            return -1;
    } while (target[++i] == '\0');
    return i;
}

/**
 *
 * @param from
 * @param to
 * @param start
 * @param end
 */
void mstrcpy(char *from, char *to, int start, int end) {
    if (from == NULL)
        return;
    int i;
    for (i = 0; i <= end - start; ++i)
        to[i] = from[i + start];
    to[i] = '\0';
}
/**
 * 判断字符是否为字母(包含'_')
 * @param c 字符
 * @return isLetter
 */
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

/**
 * 判断字符是否为数字
 * @param c 字符
 * @return isDigit
 */
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

char symbols[] = {'(', ')', ',', ';', '<', '>', '{', '}', '[', ']'};

/**
 * 判断字符是否属于边界符中
 * @param c 字符
 * @return i>=0 to symbol index and i=-1 to not match
 */
int isSymbol(char c) {
    for (int i = 0; i < sizeof(symbols) / sizeof(char); ++i) {
        if (c == symbols[i])
            return i;
    }
    return -1;
}

//单字符,无前缀性，优先在前面
char *operators[] = {"+", "-", "*", "/", "%", "&&", "||", "=", "==", "!", "!=", "<", "<=", ">", ">="};

/**
 * 判断字符串是否属于算数运算符
 * @return index in operators -1 means not match
 */
int isOperator() {
    char *str = wordStr + wordi;
    for (int i = 0; i < 6; ++i) {//to ||
        if (isPrefix(str, operators[i]))
            return i;
    }
    if (str[0] == '=') {
        if (str[1] == '=') {
            wordi++;
            return 8;
        }
        return 7;
    }
    if (str[0] == '!') {
        if (str[1] == '=') {
            wordi++;
            return 10;
        }
        return 9;
    }
    if (str[0] == '<') {
        if (str[1] == '=') {
            wordi++;
            return 12;
        }
        return 11;
    }
    if (str[0] == '>') {
        if (str[1] == '=') {
            wordi++;
            return 14;
        }
        return 13;
    }
    return -1;
}

//sorted
char *keywords[] = {"break", "const", "continue", "do", "else", "for", "if", "int", "main", "return", "void",
                    "while"};

/**
 * 对于已判合法的word断断是否是keyword
 * @param str
 * @return isKeyWord
 */
int isKeyWord(char str[]) {
    unsigned int len = strlen(str);

    for (int i = 0; i < sizeof(keywords) / sizeof(char *); ++i) {
        if (strcmp(str, keywords[i]) == 0)
            return 2;
    }
    return 1;//不是keyword则判为identifier
}


char *wordStr;
int wordi;

int S() {
    isOperator();
    //S开始一定不为空
    char c = wordStr[wordi++];
    if (isLetter(c))
        return A();
    if (isDigit(c))
        return B();
    if (isSymbol(c) != -1)
        return C();
    return 0;//未知字符
}


int A() {
    char c = wordStr[wordi++];
    if (isLetter(c) || isDigit(c))
        return A();
    return 1;
}

int B() {
    char c = wordStr[wordi++];
    if (isDigit(c))
        return B();
    return 3;
}

int C() {
    wordi++;
    return 5;
}

//**
// * 判断合法并分类
// * @param str 单个单词
// * @return 1-5 kind 0 null -1 illegal -2 len0
// */
//int legal(char str[]) {
//    if (str == NULL)
//        return 0;//null异常
//
//    wordLen = strlen(str);
//    if (wordLen == 0)
//        return -2;//_wordLen异常
//
//    //进行状态转移处理
//    wordStr = str;
//    wordi = 0;
//
//    return S();
//}

void loadTokens() {
    char *tokenNames[] = {"错误", "标识符", "基本字", "常数", "运算符", "界符"};
    for (int i = 0; i <= 5; ++i) {
        tokens[i].kind = i;
        tokens[i].name = tokenNames[i];
    }
}

int main() {
    loadTokens();
    printf("从文件输入1从命令行输入0\n");
    int flag;
    do {
        printf("请输入:");
        scanf("%d", &flag);
    } while (flag != 0 && flag != 1);
    FILE *out = fopen("out.txt", "w+");
    wordStr = (char *) malloc(sizeof(char *));
    if (flag == 0) {
        while (scanf("%s", wordStr) != EOF) {
            wordi = 0;
            while (wordStr[wordi] != '\0') {
                while (wordStr[wordi] == ' ') wordi++;
                struct Word *word = (struct Word *) malloc(sizeof(struct Word));
                int mark = wordi;
                word->kind = S();
                word->value = (char *) malloc(sizeof(char) * (wordi - mark + 2));
                mstrcpy(wordStr, word->value, mark, wordi);

                fprintf(out, "%s : %s\n", tokens[word->kind].name, word->value);
                printf("%s : %s\n", tokens[word->kind].name, word->value);
            }
        }
    }
    return 0;
}