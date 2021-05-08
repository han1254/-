//
// Created by han1254 on 5/7/21.
//
#include "stdlib.h"
#include "stdio.h"
void PreToPost(char pre[], int preStart, int preEnd,
               char post[], int postStart, int postEnd) {
    int half;
    if (preEnd >= preStart) {
        post[postEnd] = pre[preStart];
        half = (preEnd - preStart) / 2;
        PreToPost(pre, preStart + 1, preStart + half, post, postStart, postStart + half - 1);
        PreToPost(pre, preStart + half + 1, preEnd, post, postStart + half, postEnd - 1);
    }
}

int main() {
    //    A
    //  B    C
    //D  E F   G

    char* t = "ABDECFG";
    char* res = (char*)malloc(sizeof(char));
    PreToPost(t, 0, 6, res, 0, 6);
    res[7] = '\0';

    printf("%s\n", res);
}