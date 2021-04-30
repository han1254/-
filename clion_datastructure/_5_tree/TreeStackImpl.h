//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_TREESTACKIMPL_H
#define CLION_DATASTRUCTURE_TREESTACKIMPL_H
#include "BiTNode.h"
#include "stdio.h"
#define MaxTreeStackSize 100
/**
 * top指向栈顶，初始值为-1
 */
typedef struct {
    BiTree stack[MaxTreeStackSize];
    int top;
} TreeStack;


void InitTreeStack(TreeStack* stack) {
    stack->top = -1;
}

int Pop(TreeStack* stack, BiTree* tree) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    *tree = stack->stack[stack->top--];
    return 1;
}

int Push(TreeStack* stack, BiTree tree) {
    if (stack->top == MaxTreeStackSize - 1) {
        printf("Stack is full\n");
        return 0;
    }
    stack->stack[++stack->top] = tree;
    return 1;
}

int GetTop(TreeStack stack, BiTree* tree) {
    if (stack.top == -1) {
        return 0;
    }
    *tree = stack.stack[stack.top];
    return 1;
}

int StackEmpty(TreeStack stack) {
    if (stack.top == -1) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_TREESTACKIMPL_H
