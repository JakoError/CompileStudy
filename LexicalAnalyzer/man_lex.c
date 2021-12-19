//
// Created by JakoError on 2021/10/13.
//
#include "man_lex.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * ÿ���������ֳ����Ĵ�
 * @param kind ����Token�е�kind(index)
 * @param value wordֵ
 */
struct Word {
    int kind;
    char *value;
};
//struct Word **words;//words��̬�����С(������û��ʹ��)
//int wordsLayer = 0;
//int wordsi = 0;

/**
 * 0-��ʶ�� identifier
 * 1-������ keyword
 * 2-���� const
 * 3-����� operator
 * 4-��� bounds
 */
struct Token {
    int kind;
    char *name;
} tokens[6];

/**
 * ����o�Ķ�target�ж��Ƿ���ͬ������o�в�����ȫ��ȣ������ж�o�ǲ�����target��ͷ
 * @param o ��Ҫ�����жϵ��ַ���
 * @param target �Ƚϵ��ض��ַ���
 * @return true-- length of target  false-- -1 null-- -1
 */
int isPrefix(char *o, char *target) {
    if (o == NULL || target == NULL)
        return -1;
    int i = 0;
    do {
        if (o[i] != target[i])
            return -1;
    } while (target[++i] != '\0');
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
 * �ж��ַ��Ƿ�Ϊ��ĸ(����'_')
 * @param c �ַ�
 * @return isLetter
 */
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

/**
 * �ж��ַ��Ƿ�Ϊ����
 * @param c �ַ�
 * @return isDigit
 */
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

char symbols[] = {'(', ')', ',', ';', '<', '>', '{', '}', '[', ']'};

/**
 * �ж��ַ��Ƿ����ڱ߽����
 * @param c �ַ�
 * @return i>=0 to symbol index and i=-1 to not match
 */
int isSymbol(char c) {
    for (int i = 0; i < sizeof(symbols) / sizeof(char); ++i) {
        if (c == symbols[i])
            return i;
    }
    return -1;
}

//���ַ�,��ǰ׺�ԣ�������ǰ��
char *operators[] = {"+", "-", "*", "/", "%", "&&", "||", "=", "==", "!", "!=", "<", "<=", ">", ">="};

/**
 * �ж��ַ����Ƿ��������������
 * @return index in operators -1 means not match
 */
int isOperator() {
    char *str = wordStr + wordi;
    for (int i = 0; i <= 6; ++i) {//to ||
        int len = isPrefix(str, operators[i]);
        if (len != -1) {
            wordi += len;
            return i;
        }
    }
    if (str[0] == '=') {
        wordi++;
        if (str[1] == '=') {
            wordi++;
            return 8;
        }
        return 7;
    }
    if (str[0] == '!') {
        wordi++;
        if (str[1] == '=') {
            wordi++;
            return 10;
        }
        return 9;
    }
    if (str[0] == '<') {
        wordi++;
        if (str[1] == '=') {
            wordi++;
            return 12;
        }
        return 11;
    }
    if (str[0] == '>') {
        wordi++;
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
 * �������кϷ���word�϶��Ƿ���keyword
 * @param str
 * @return isKeyWord
 */
int isKeyWord(char str[]) {
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); ++i) {
        if (strcmp(str, keywords[i]) == 0)
            return i;
    }
    return -1;//����keyword����Ϊidentifier
}


char *wordStr;
int wordi;

int S() {
    int code = isOperator();
    if (code != -1)
        return 4;
    //S��ʼһ����Ϊ��
    char c = wordStr[wordi];//S()����Ҫ++
    if (isLetter(c))
        return A();
    if (isDigit(c))
        return B();
    if (isSymbol(c) != -1)
        return C();
    //δƥ������
    ++wordi;
    return 0;//δ֪�ַ�
}


int A() {
    char c = wordStr[++wordi];
    if (isLetter(c) || isDigit(c))
        return A();
    return 1;
}

int B() {
    char c = wordStr[++wordi];
    if (isDigit(c))
        return B();
    return 3;
}

int C() {
    ++wordi;
    return 5;
}

void loadTokens() {
    char *tokenNames[] = {"����", "��ʶ��", "������", "����", "�����", "���"};
    for (int i = 0; i <= 5; ++i) {
        tokens[i].kind = i;
        tokens[i].name = tokenNames[i];
    }
}

int getNextWord(char *str, bool flag, FILE *in) {
    if (flag)
        return fscanf(in, "%s", str);
    return scanf("%s", str);
}

int main() {
    loadTokens();
    printf("���ļ�����\t1\n������������\t0\n");
    char inflag;
    do {
        printf("������:");
        scanf("%c", &inflag);
    } while (inflag != '0' && inflag != '1');
    FILE *in = NULL;
    FILE *out = fopen("out.txt", "w+");
    wordStr = (char *) malloc(sizeof(char *));
    if (inflag == '1') {
        char *inPath = (char *) malloc(sizeof(char *));
        do {
            printf("open fail errno = %d reason %s\n", errno, strerror(errno));
            printf("Դ�ļ�·��(Ĭ��in.sy):");
            scanf("%s", inPath);
//            inPath = "whileif.sy";
            printf("\n%s\n", inPath);
            in = fopen(inPath, "r");
        } while (in == NULL);
//        in = fopen("in.sy","r");
    }
    while (getNextWord(wordStr, inflag == '1', in) != EOF) {
        wordi = 0;
        while (wordStr[wordi] != '\0') {
            while (wordStr[wordi] == ' ') wordi++;
            struct Word *word = (struct Word *) malloc(sizeof(struct Word));
            int mark = wordi;
            //����ע��
            if (isPrefix(wordStr + wordi, "//") != -1) {
                while (getchar() != '\n');
                break;
            }
            if (isPrefix(wordStr + wordi, "/*") != -1) {
                char c;
                do {
                    do {
                        c = (char) getchar();
                    } while (c != '*');
                } while (getchar() != '/');
                break;
            }
            word->kind = S();
            word->value = (char *) malloc(sizeof(char) * (wordi - mark + 2));
            mstrcpy(wordStr, word->value, mark, wordi - 1);

            if (word->kind == 1 && isKeyWord(word->value) != -1)
                word->kind = 2;

            fprintf(out, "%s:\t%s\n", tokens[word->kind].name, word->value);
            printf("%s:\t%s\n", tokens[word->kind].name, word->value);
            fflush(out);
        }
    }
    if (in != NULL)
        fclose(in);
    fclose(out);
    return 0;
}


