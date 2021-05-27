//
// Created by han1254 on 5/22/21.
//

#ifndef CLION_DATASTRUCTURE_LINKLISTIMPL_H
#define CLION_DATASTRUCTURE_LINKLISTIMPL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"

void printList(LinkList list) {
    LinkList node = list;
    while(node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

void printList1(LinkList* l) {//LinkList& l
    while ((*l) != NULL) {
        printf("%d ", (*l)->data);
        *l = (*l)->next;
    }
}

void printList2(LinkList* l) {//LinkList& l
    LinkList node = *l;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

LinkList CreateList(int a[], int n) {
    LinkList hnode = (LinkList)malloc(sizeof(LNode));
    hnode->data = a[0];
    LinkList node = hnode;
    for (int i = 1; i < n; ++i) {
        LinkList tnode = (LinkList)malloc(sizeof(LNode));
        tnode->data = a[i];
        node->next = tnode;
        node = node->next;
    }
    node->next = NULL;
    return hnode;
}

void Del_X_3(LinkList* L, int x) {
    LNode* p;
    if (*L == NULL) {
        return;
    }
    if ((*L)->data == x) {
        p = *L;
        *L = (*L)->next;
        free(p);
        Del_X_3(L, x);
    } else
        Del_X_3(&(*L)->next, x);
}
#endif //CLION_DATASTRUCTURE_LINKLISTIMPL_H
