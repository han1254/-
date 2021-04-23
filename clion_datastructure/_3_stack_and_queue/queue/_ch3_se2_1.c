//
// Created by han1254 on 4/23/21.
// 在Queue中设置Tag域
//
#include <stdio.h>
#define MaxSize 10
typedef struct Queue {
    int data[MaxSize];
    int front,rear;
    int tag;
} TagQueue;

void PrintTagQueue(TagQueue tagQueue) {
    if (tagQueue.tag == 0 && tagQueue.front == tagQueue.rear) {
        printf("TagQueue is empty\n");
        return;
    }
    int start = tagQueue.front;
    int end = (tagQueue.rear - 1 + MaxSize) % MaxSize;
    printf("<");
    while(start != end) {
        printf("%d ", tagQueue.data[start]);
        start = (start + 1) % MaxSize;
    }
    printf("%d", tagQueue.data[start]);
    printf("<\n");
    printf("front: %d, rear: %d, tag: %d\n", tagQueue.front, tagQueue.rear, tagQueue.tag);
}

void InitQueue_Tag(TagQueue* tagQueue) {
    tagQueue->front = 0;
    tagQueue->rear = 0;
    tagQueue->tag = 0;
}

int EnQueue_Tag(TagQueue* tagQueue, int e) {
    if (tagQueue->tag == 1 && tagQueue->rear == tagQueue->front) {
        printf("TagQueue is full.\n");
        return 0;
    }
    tagQueue->data[tagQueue->rear] = e;
    tagQueue->rear = (tagQueue->rear + 1) % MaxSize;
    tagQueue->tag = 1;
    return 1;
}

int DeQueue_Tag(TagQueue* tagQueue, int* res) {
    if (tagQueue->front == tagQueue->rear && tagQueue->tag == 0) {
        printf("TagQueue is Empty.\n");
        return 0;
    }
    *res = tagQueue->data[tagQueue->front];
    tagQueue->front = (tagQueue->front + 1) % MaxSize;
    tagQueue->tag = 0;
    return 1;
}

void dequeue(TagQueue* queue, int* res) {
    printf("**********************\n");
    DeQueue_Tag(queue, res);
    printf("dequeue, %d\n", *res);
    PrintTagQueue(*queue);
    printf("**********************\n");
}

int main() {
    TagQueue queue;
    InitQueue_Tag(&queue);
    EnQueue_Tag(&queue, 1);
    EnQueue_Tag(&queue, 2);
    EnQueue_Tag(&queue, 3);
    EnQueue_Tag(&queue, 4);
    EnQueue_Tag(&queue, 5);
    EnQueue_Tag(&queue, 6);
    EnQueue_Tag(&queue, 7);
    EnQueue_Tag(&queue, 8);
    EnQueue_Tag(&queue, 9);
    EnQueue_Tag(&queue, 10);
    PrintTagQueue(queue);
    int res;

    for (int i = 0; i < 10; ++i) {
        dequeue(&queue, &res);
    }
}