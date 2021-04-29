//
// Created by han1254 on 4/25/21.
//
#include "SString.h"
int main() {
    SString S;
    SString T;
//    StrAssign(S);
//    StrAssign(T);
    char* s = "ababcabcacbab\0";
    char* t = "abcac\0";

    StrAssign(S, s);
    StrAssign(T, t);

    printf("%d\n", Index_KMP(S, T, 1));

}