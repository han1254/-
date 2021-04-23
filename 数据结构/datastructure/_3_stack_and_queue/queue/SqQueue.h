/**
 *
 * Creator: han1254
 * Email:1254763408@qq.com
 *
 * 顺序队列
 *
 * */
#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int front, rear;
} SqQueue;


#endif
