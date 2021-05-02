//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_BITREESTACKIMPL_H
#define CLION_DATASTRUCTURE_BITREESTACKIMPL_H
#include "BiTree.h"
#include "stdio.h"
#define MaxTreeStackSize 100
/**
 * top指向栈顶，初始值为-1
 */
typedef struct {
    BiTree stack[MaxTreeStackSize];
    int top;
} BiTreeStack;


void InitTreeStack(BiTreeStack* stack) {
    stack->top = -1;
}

int Pop(BiTreeStack* stack, BiTree* tree) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    *tree = stack->stack[stack->top--];
    return 1;
}

int Push(BiTreeStack* stack, BiTree tree) {
    if (stack->top == MaxTreeStackSize - 1) {
        printf("Stack is full\n");
        return 0;
    }
    stack->stack[++stack->top] = tree;
    return 1;
}

int GetTop(BiTreeStack stack, BiTree* tree) {
    if (stack.top == -1) {
        return 0;
    }
    *tree = stack.stack[stack.top];
    return 1;
}

int StackEmpty(BiTreeStack stack) {
    if (stack.top == -1) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_BITREESTACKIMPL_H
