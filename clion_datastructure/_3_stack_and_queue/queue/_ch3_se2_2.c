//
// Created by han1254 on 4/23/21.
// 用队列和栈实现队列的元素逆序
//
#include "problem_common.h"
void reverse(Queue* queue, Stack* stack) {
    int res;
    while(!QueueEmpty(*queue)) {
        DeQueue(queue, &res);
        Push(stack, res);
    }
    while (!StackEmpty(*stack)) {
        Pop(stack, &res);
        EnQueue(queue, res);
    }

    PrintQueue(*queue);
}

int main() {
    Queue queue;
    Stack stack;
    InitQueue(&queue);
    InitStack(&stack);
    EnQueue(&queue, 5);
    EnQueue(&queue, 4);
    EnQueue(&queue, 3);
    EnQueue(&queue, 2);
    EnQueue(&queue, 1);
    printf("Queue:\n");
    PrintQueue(queue);
    printf("reverse\n");
    reverse(&queue, &stack);
}