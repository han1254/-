//
// Created by han1254 on 4/23/21.
//
typedef struct LCQNode {
    int data;
    struct LCQNode* next;
} LCycleQueueNode;

typedef struct {
    LCycleQueueNode* front;
    LCycleQueueNode* rear;
} LinkCycleQueue;




