#include <stdio.h>
#include "SqStackImpl.h"

int main()
{
	SqStack s;
	InitStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	PrintStack(s);
}
