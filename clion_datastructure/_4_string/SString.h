//
// Created by han1254 on 4/25/21.
//

#ifndef CLION_DATASTRUCTURE_SSTRING_H
#define CLION_DATASTRUCTURE_SSTRING_H
#define MAXSTRLEN 255//255是2的8次方，是一个字节所能表示的最大的长度

#include <stdlib.h>
#include "stdio.h"
typedef unsigned char SString[MAXSTRLEN + 1];//第一个字节，即[0]位置上的字符，使用其int值来表示串长度


void StrAssign(unsigned char* S, const char* chars) {

    int len = 0;
    int i = 1;
    while (chars[len] != '\0') {
        S[i++] = chars[len++];
    }
    S[0] = len;
}

void StrInput(unsigned char* S) {
    char* chars = (char*)malloc(sizeof(char));
    printf("enter the string:\n");
    scanf("%s", chars);
    StrAssign(S, chars);
}

int Index_Slow(const SString S, const SString T, int pos) {
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T[0]) return i - T[0];//此时i也到了匹配的最后一位的后一位，所以直接i-T[0]，不用加一
    return 0;
}

void get_next(const SString T, int next[]) {

    int i = 1, j = 0;
    next[1] = 0;
    printf("初始化：next[1] = 0\n");
    while (i < T[0]) {//只需要到达倒数第二位就行，目的是通过倒数第二位来计算倒数第一位，动态规划的思想
        printf("***********************************\n");
        printf("j = %d\n T[i = %d] = %c\n T[j = %d] = %c\n", j, i, T[i], j, T[j]);
        if (j == 0 || T[i] == T[j]) {
            if (j == 0) {
                printf("模式串指针j = 0\n");
            } else {
                printf("T[i = %d](%c) == T[j = %d](%c)\n", i, T[i], j, T[j]);
            }
            next[i + 1] = j + 1;
            printf("T[j(%d) + 1] = %d + 1\n", i, j);
            i++;
            j++;
        } else {
            j = next[j];
            printf("改变串模式指针j = %d -> next[j] = %d\n", j, next[j]);
        }
    }
}


void get_next_val(const SString T, int nextval[]) {
    nextval[1] = 0;
    int i = 1, j = 0;
    while(i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            if (T[i + 1] != T[j + 1]) {
                nextval[i + 1] = j + 1;
            } else nextval[i + 1] = nextval[j + 1];
            i++;
            j++;
        } else {
            j = nextval[j];
        }
    }
}

int Index_KMP(const SString S, const SString T, int pos) {
    int* next = (int*)malloc(sizeof(int));
    get_next(T, next);
    //get_next_val(T, next);
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            //【关于j为0的思考】：如果j==0,二话不说，直接i++,j++，直接让S的i+1位和T的1位对齐，开始判断
            // 因为如果j=0,则说明找不到
            i++;
            j++;
        } else j = next[j];
    }
    if (j > T[0]) return i - T[0];
    return 0;
}



#endif //CLION_DATASTRUCTURE_SSTRING_H
