//
// Created by han1254 on 4/24/21.
//

#include "stdio.h"

#define MaxSize 100
typedef struct {
    int res;
    int n;
} CurNode;


typedef struct {
    CurNode data[MaxSize];
    int top;
} CurStack;



int Pn_cur(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return 2 * x;
    return 2 * x * Pn_cur(x, n - 1) - 2 * (n - 1) * Pn_cur(x, n - 2);
}

int Pn(int x, int n) {
    CurStack stack;
    stack.top = -1;

    for (int i = n; i >= 2; i--) {
        stack.data[++stack.top].n = i;
    }
    int va1 = 1;
    int va2 = 2 * x;
    while(stack.top >= 0) {
        stack.data[stack.top].res = 2 * x * va2 - 2 * (stack.data[stack.top].n - 1) * va1;
        va1 = va2;
        va2 = stack.data[stack.top].res;
        stack.top--;
    }
    if (n == 0) {
        return va1;
    }
    return va2;
}

int main() {
    printf("%d\n", Pn(3, 3));
}