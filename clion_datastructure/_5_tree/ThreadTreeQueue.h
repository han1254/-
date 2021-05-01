//
// Created by han1254 on 5/1/21.
//

#ifndef CLION_DATASTRUCTURE_THREADTREEQUEUE_H
#define CLION_DATASTRUCTURE_THREADTREEQUEUE_H
#include "ThreadTree.h"
#include "stdio.h"
#define MaxTreeQueueSize 100
typedef struct {
    ThreadTree queue[MaxTreeQueueSize];
    int front, rear;
} ThreadTreeQueue;


void InitQueue(ThreadTreeQueue* queue) {
    queue->rear = queue->front = 0;
}

int Enqueue(ThreadTreeQueue* queue, ThreadTree node) {
    if ((queue->rear + 1) % MaxTreeQueueSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->queue[queue->rear] = node;
    queue->rear = (queue->rear + 1) % MaxTreeQueueSize;
    return 1;
}

int Dequeue(ThreadTreeQueue* queue, ThreadTree* res) {
    if (queue->rear == queue->front) {
        printf("Queue is empty\n");
        return 0;
    }
    *res = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MaxTreeQueueSize;
    return 1;
}

int QueueEmpty(ThreadTreeQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}


#endif //CLION_DATASTRUCTURE_THREADTREEQUEUE_H
