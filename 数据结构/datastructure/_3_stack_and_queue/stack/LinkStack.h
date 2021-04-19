//
// Created by han1254 on 4/18/21.
//

#ifndef CLION_DATASTRUCTURE_LINKSTACK_H
#define CLION_DATASTRUCTURE_LINKSTACK_H
#include "stack_common.h"
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkStackNode, *LinkStack;

int Init_Link_Stack(LinkStack* head);

int Push_Link_Stack(LinkStack head, ElemType data);

int Pop_Link_Stack(LinkStack head, ElemType* res);

int Is_Empty_Link_Stack(LinkStack head);

#endif //CLION_DATASTRUCTURE_LINKSTACK_H
