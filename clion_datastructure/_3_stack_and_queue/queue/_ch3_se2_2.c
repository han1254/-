//
// Created by han1254 on 4/23/21.
// 用队列和栈实现队列的元素逆序
//
#include "stdio.h"
#include "stdlib.h"
#define MaxSize 6
typedef struct {
    int data[MaxSize];
    int front, rear;
} Queue;

typedef struct {
    int data[MaxSize];
    int top;
} Stack;

static int resArr[MaxSize];
static int ptr = 0;
void InitQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

void PrintQueue(Queue queue) {
    int start = queue.front;
    int end = queue.rear;
    printf("<");
    while(start != end) {
        printf("%d ", queue.data[start]);
        start = (start + 1) % MaxSize;
    }
    printf("<\n");
}

int QueueEmpty(Queue queue) {
    if (queue.front == queue.rear) return 1;
    return 0;
}

int EnQueue(Queue* queue, int e) {
    if ((queue->rear + 1) % MaxSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MaxSize;
    return 1;
}

int DeQueue(Queue* queue, int* e) {
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

int Push(Stack* stack, int data) {
    if (stack->top == MaxSize) {
        printf("Stack is full\n");
        return 0;
    }
    stack->data[++stack->top] = data;
    return 1;
}

int Pop(Stack* stack, int* res) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    *res = stack->data[stack->top--];
    return 1;
}

int StackEmpty(Stack stack) {
    if (stack.top == -1) return 1;
    return 0;
}
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