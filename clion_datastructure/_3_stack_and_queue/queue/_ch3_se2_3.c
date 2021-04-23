//
// Created by han1254 on 4/23/21.
//
#include "problem_common.h"

int Enqueue(Stack* stack1, Stack* stack2, int data) {
    if (!StackOverflow(*stack1)) {
        Push(stack1, data);
        printf("%d入队\n", data);
        return 1;
    }
    if (!StackEmpty(*stack2)) {
        printf("Stack is full!\n");
        return 0;
    }
    int x;
    while(!StackEmpty(*stack1)) {
        Pop(stack1, &x);
        Push(stack2, x);
    }
    Push(stack1, data);
    printf("%d入队\n", data);
    return 1;
}

int Dequeue(Stack* stack1, Stack* stack2, int* res) {
    if (!StackEmpty(*stack2)) {
        Pop(stack2, res);
        printf("%d出队\n", *res);
        return 1;
    }
    if (StackEmpty(*stack1)) {
        printf("Queue is empty\n");
        return 0;
    }

    while(!StackEmpty(*stack1)) {
        int x;
        Pop(stack1, &x);
        Push(stack2, x);
    }

    Pop(stack2, res);
    printf("%d出队\n", *res);
    return 1;
}

int main() {
    Stack s1;
    Stack s2;
    InitStack(&s1);
    InitStack(&s2);

    Enqueue(&s1, &s2, 1);
    Enqueue(&s1, &s2, 2);
    Enqueue(&s1, &s2, 3);
    Enqueue(&s1, &s2, 4);
    Enqueue(&s1, &s2, 5);
    int res;
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
    Enqueue(&s1, &s2, 6);
    Enqueue(&s1, &s2, 7);
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
    Dequeue(&s1, &s2, &res);
}