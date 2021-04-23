//
// Created by han1254 on 4/23/21.
//

#ifndef CLION_DATASTRUCTURE_LINKQUEUE_H
#define CLION_DATASTRUCTURE_LINKQUEUE_H

typedef struct LinkQNode {
    int data;
    struct LinkQNode* next;
} LinkQueueNode;

typedef struct {
    LinkQueueNode *front, *rear;
} LinkQueue;


#endif //CLION_DATASTRUCTURE_LINKQUEUE_H
