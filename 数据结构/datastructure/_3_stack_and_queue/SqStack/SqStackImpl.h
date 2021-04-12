#ifndef SQSTACK_IMPL_H
#define SQSTACK_IMPL_H
#include "SqStack.h"
#include "stdlib.h"
void PrintStack(SqStack S)
{
	for(int i = 0; i <= S.top; i++)
	{
		printf("%d\n", S.data[i]);
	}
}
void InitStack(SqStack* S)
{
	S->data = (int*)malloc(MaxSize * sizeof(int));
	S->top = -1;
}

int StackEmpty(SqStack S)
{
	if(S.top == -1) return 0;
	return 1;
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

int GetTOp(SqStack S, int* e)
{
	if(S.top == -1) return 0;
	*e = S.data[S.top];
	return 1;
}
#endif
