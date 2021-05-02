//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_BITREEQUEUEIMPL_H
#define CLION_DATASTRUCTURE_BITREEQUEUEIMPL_H
#define MaxTreeQueueSize 100
#include "BiTree.h"
#include "stdio.h"
typedef struct {
    BiTree queue[MaxTreeQueueSize];
    int front, rear;
} BiTreeQueue;


void InitQueue(BiTreeQueue* queue) {
    queue->rear = queue->front = 0;
}

int Enqueue(BiTreeQueue* queue, BiTree node) {
    if ((queue->rear + 1) % MaxTreeQueueSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->queue[queue->rear] = node;
    queue->rear = (queue->rear + 1) % MaxTreeQueueSize;
    return 1;
}

int Dequeue(BiTreeQueue* queue, BiTree* res) {
    if (queue->rear == queue->front) {
        printf("Queue is empty\n");
        return 0;
    }
    *res = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MaxTreeQueueSize;
    return 1;
}

int QueueEmpty(BiTreeQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_BITREEQUEUEIMPL_H
