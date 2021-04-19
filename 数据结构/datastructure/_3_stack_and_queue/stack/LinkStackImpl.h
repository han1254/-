//
// Created by han1254 on 4/19/21.
//

#ifndef CLION_DATASTRUCTURE_LINKSTACKIMPL_H
#define CLION_DATASTRUCTURE_LINKSTACKIMPL_H
#include "LinkStack.h"

void Print_Stack_Link_Stack(LinkStack stack) {
    LinkStack node = stack->next;
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int Init_Link_Stack(LinkStack* stack) {
    *stack = (LinkStack)malloc(sizeof(LinkStackNode));
    if (!*stack) return 0;
    return 1;
}

int Push_Link_Stack(LinkStack head, ElemType data) {
    LinkStack node = (LinkStack)malloc(sizeof(LinkStackNode));
    if (!node) return 0;
    node->data = data;
    node->next = head->next;
    head->next = node;
    return 1;
}

int Pop_Link_Stack(LinkStack head, ElemType* res) {
    if (!head->next) return 0;
    LinkStack node = head->next;
    head->next = node->next;
    *res = node->data;
    free(node);
    return 1;
}

int Is_Empty_Link_Stack(LinkStack stack) {
    if (!stack->next) return 1;
    return 0;
}

#endif //CLION_DATASTRUCTURE_LINKSTACKIMPL_H
