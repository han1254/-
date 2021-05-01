//
// Created by han1254 on 5/1/21.
//

#ifndef CLION_DATASTRUCTURE_THREADTREESTACK_H
#define CLION_DATASTRUCTURE_THREADTREESTACK_H
#define MaxTreeStackSize 100
#include "ThreadTree.h"
#include "stdio.h"
/**
 * top指向栈顶，初始值为-1
 */
typedef struct {
    ThreadTree stack[MaxTreeStackSize];
    int top;
} ThreadTreeStack;


void InitTreeStack(ThreadTreeStack* stack) {
    stack->top = -1;
}

int Pop(ThreadTreeStack* stack, ThreadTree* tree) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    *tree = stack->stack[stack->top--];
    return 1;
}

int Push(ThreadTreeStack* stack, ThreadTree tree) {
    if (stack->top == MaxTreeStackSize - 1) {
        printf("Stack is full\n");
        return 0;
    }
    stack->stack[++stack->top] = tree;
    return 1;
}

int GetTop(ThreadTreeStack stack, ThreadTree* tree) {
    if (stack.top == -1) {
        return 0;
    }
    *tree = stack.stack[stack.top];
    return 1;
}

int StackEmpty(ThreadTreeStack stack) {
    if (stack.top == -1) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_THREADTREESTACK_H
