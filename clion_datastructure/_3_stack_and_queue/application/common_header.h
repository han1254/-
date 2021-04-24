//
// Created by han1254 on 4/24/21.
//

#ifndef CLION_DATASTRUCTURE_COMMON_HEADER_H
#define CLION_DATASTRUCTURE_COMMON_HEADER_H
#include "stdio.h"
#define MaxSize 100
typedef struct {
    char data[MaxSize];
    int front, rear;
} Queue;

typedef struct {
    char data[MaxSize];
    int top;
} Stack;

void InitQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

void PrintQueue(Queue queue) {
    int start = queue.front;
    int end = queue.rear;
    printf("<");
    while(start != end) {
        printf("%c ", queue.data[start]);
        start = (start + 1) % MaxSize;
    }
    printf("<\n");
}

void PrintStack(Stack stack) {
    for (int i = 0; i <= stack.top; ++i) {
        printf("%c", stack.data[i]);
    }
    printf("\n");
}

int QueueEmpty(Queue queue) {
    if (queue.front == queue.rear) return 1;
    return 0;
}

int EnQueue(Queue* queue, char e) {
    if ((queue->rear + 1) % MaxSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MaxSize;
    return 1;
}

int DeQueue(Queue* queue, char* e) {
    if (queue->rear == queue->front) {
        printf("Queue is empty\n");
        return 0;
    }
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % MaxSize;
    return 1;
}

void InitStack(Stack* stack) {
    stack->top = -1;
}

int Push(Stack* stack, char data) {
    if (stack->top == MaxSize) {
        printf("Stack is full\n");
        return 0;
    }
    stack->data[++stack->top] = data;
    return 1;
}

int Pop(Stack* stack, char* res) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    *res = stack->data[stack->top--];
    return 1;
}

char GetTop(Stack stack) {
    if (stack.top == -1) {
        printf("Stack is empty!!!!!!!!!!!\n");
        return 0;
    }
    return stack.data[stack.top];

}

int StackEmpty(Stack stack) {
    if (stack.top == -1) return 1;
    return 0;
}

int StackOverflow(Stack stack) {
    if (stack.top == MaxSize - 1) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_COMMON_HEADER_H
