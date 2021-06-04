//
// Created by han1254 on 4/18/21.
//

#ifndef CLION_DATASTRUCTURE_SQSTACKIMPL_H
#define CLION_DATASTRUCTURE_SQSTACKIMPL_H

#include <malloc.h>
#include <stdio.h>
#include "SqStack.h"

void PrintStack(SqStack S)
{
    for(int i = S.top; i >= 0; i--)
    {
        printf("%d\n", S.data[i]);
    }
}
void InitStack(SqStack* S)
{
    S->top = -1;
}

int StackEmpty(SqStack S)
{
    if(S.top == -1) return 1;
    return 0;
}

int Push(SqStack* S, int x)
{
    if(S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}

int Pop(SqStack* S, int* e)
{
    if(S->top == -1) return 0;
    *e = S->data[S->top--];
    return 1;
}

int GetTop(SqStack S, int* e)
{
    if(S.top == -1) return 0;
    *e = S.data[S.top];
    return 1;
}

#endif //CLION_DATASTRUCTURE_SQSTACKIMPL_H
