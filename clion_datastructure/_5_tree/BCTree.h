//
// Created by han1254 on 5/12/21.
//

#ifndef CLION_DATASTRUCTURE_BCTREE_H
#define CLION_DATASTRUCTURE_BCTREE_H

#include <stdio.h>

#define MaxTreeQueueSize 100
typedef struct BCNode {
    char data;
    struct BCNode *lchild, *rchild;
    int count;
}BCNode, *BiCTree;

typedef struct {
    BiCTree queue[MaxTreeQueueSize];
    int front, rear;
} BiCTreeQueue;


void InitQueue(BiCTreeQueue* queue) {
    queue->rear = queue->front = 0;
}

int Enqueue(BiCTreeQueue* queue, BiCTree node) {
    if ((queue->rear + 1) % MaxTreeQueueSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->queue[queue->rear] = node;
    queue->rear = (queue->rear + 1) % MaxTreeQueueSize;
    return 1;
}

int Dequeue(BiCTreeQueue* queue, BiCTree* res) {
    if (queue->rear == queue->front) {
        printf("Queue is empty\n");
        return 0;
    }
    *res = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MaxTreeQueueSize;
    return 1;
}

int QueueEmpty(BiCTreeQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}
#endif //CLION_DATASTRUCTURE_BCTREE_H
