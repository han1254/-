//
// Created by han1254 on 4/18/21.
//
#include "SqStackImpl.h"

int main()
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

