//
// Created by han1254 on 4/18/21.
//
#ifndef SQ_STACK_MAIN_H
#define SQ_STACK_MAIN_H
#include "SqStackImpl.h"

void doSth_SqStackMain()
{
    SqStack s;
    InitStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    int res;
    Pop(&s, &res);
    Push(&s, 5);
    PrintStack(s);
}

#endif