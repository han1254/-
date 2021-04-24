//
// Created by han1254 on 4/23/21.
//
#include "stdlib.h"
#include "stdio.h"
typedef struct LCQNode {
    int data;
    struct LCQNode* next;
} LCycleQueueNode;

typedef struct {
    LCycleQueueNode* front;
    LCycleQueueNode* rear;
} LinkCycleQueue;

void InitCycleQueue(LinkCycleQueue* queue) {
    queue->front = queue->rear = (LCycleQueueNode*)malloc(sizeof(LCycleQueueNode));
    queue->front->next = queue->front;
}

int Enqueue(LinkCycleQueue* queue, int data) {
    if (queue->front == queue->rear->next) {
        printf("Queue is full\n");
        LCycleQueueNode* node = (LCycleQueueNode *)malloc(sizeof(LCycleQueueNode));
        node->next = queue->rear->next;
        queue->rear->next = node;
    }

    queue->rear->data = data;
    queue->rear = queue->rear->next;
    return 1;
}

int Dequeue(LinkCycleQueue* queue, int* res) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return 0;
    }
    *res = queue->front->data;
    queue->front = queue->front->next;
    return 1;
}

int main() {
    LinkCycleQueue queue;
    InitCycleQueue(&queue);
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);
    int res;
    Dequeue(&queue, &res);
}



