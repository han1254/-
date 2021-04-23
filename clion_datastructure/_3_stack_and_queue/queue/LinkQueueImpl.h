//
// Created by han1254 on 4/23/21.
//

#ifndef CLION_DATASTRUCTURE_LINKQUEUEIMPL_H
#define CLION_DATASTRUCTURE_LINKQUEUEIMPL_H
#include "LinkQueue.h"
#include <stdlib.h>
#include <stdio.h>

void InitQueue_Link(LinkQueue* queue) {
    queue->front = queue->rear = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    queue->front->next = NULL;
}

int IsEmpty_Link(LinkQueue queue) {
    if (queue.front == queue.rear) return 1;
    return 0;
}

/**
 * []->NULL
 * ↑↑
 * fr
 * ------------
 * []->[data]->NULL
 * ↑     ↑
 * f     r
 * @param queue
 * @param e
 * @return
 */
int EnQueue_Link(LinkQueue* queue, int e) {
    LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(!node) {
        printf("Failed to init a new queue node\n");
        return 0;
    }
    node->data = e;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

/**
 * []->[data]->NULL
 * ↑     ↑
 * f     r
 * ------------删除了r后的元素
 * []->NULL
 * ↑
 * f
 * 这时候我们需要把rear指针继续指向front处
 * []->NULL
 * ↑↑
 * fr
 * @param queue
 * @param res
 * @return
 */
int DeQueue_Link(LinkQueue* queue, int* res) {
    if (queue->front == queue->rear) {
        printf("LinkQueue is Empty!\n");
        return 0;
    }
    LinkQueueNode* node = queue->front->next;
    *res = node->data;
    queue->front->next = node->next;

    if (node == queue->rear) queue->rear = queue->front;
    free(node);
    return 1;
}

#endif //CLION_DATASTRUCTURE_LINKQUEUEIMPL_H