/**
 * Creator: han1254
 * Email: 1254763408@qq.com
 * Description: 普通的队列（环形队列实现的方式）
 */

#ifndef SQ_QUEUE_IMPL_H
#define SQ_QUEUE_IMPL_H
#include "SqQueue.h"
//
//typedef struct {
//	int data[MaxSize];
//	int front, rear;
//} SqQueue;
//
void InitQueue_Sq(SqQueue* queue);
int QueueEmpty_Sq(SqQueue queue);
int EnQueue_Sq(SqQueue* queue, int data);
int DeQueue_Sq(SqQueue* queue, int* res);
int GetHead_Sq(SqQueue queue, int* res);
int QueueFull_Sq(SqQueue queue);

void PrintSqQueueTotally(SqQueue queue) {

}

void PrintSqQueue(SqQueue queue) {
	int index = queue.front;
	while(index % (MaxSize) != queue.rear) {
		printf("%d ", queue.data[index]);
		index = (index + 1) % MaxSize;
	}

	printf("%d\n", queue.data[queue.rear]);
}

void InitQueue_Sq(SqQueue* queue) {

	queue->front = 0;
	queue->rear = 0;
}

int QueueEmpty_Sq(SqQueue queue) {
	if(queue.front == queue.rear) return 1;
	return 0;
}

int QueueFull_Sq(SqQueue queue) {
	if((queue.rear + 1) % MaxSize == queue.front) return 1;
	return 0;
}

int EnQueue_Sq(SqQueue* queue, int data) {
	if((queue->rear + 1) % MaxSize == queue->front) return 0;//队列满
	queue->data[queue->rear] = data;
	queue->rear = (queue->rear + 1) % MaxSize;
	return 1;
}

int DeQueue_Sq(SqQueue* queue, int* res) {
	if(queue->rear == queue->front) return 0;//队列空
	*res = queue->data[queue->front];
	queue->front = (queue->front + 1) % MaxSize;
	return 1;
}



#endif


