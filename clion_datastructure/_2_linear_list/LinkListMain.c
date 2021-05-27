//
// Created by han1254 on 5/22/21.
//
#include "LinkListImpl.h"
int main() {
    int a[6] = {1, 3, 6, 4, 6, 8};
    LinkList h = CreateList(a, 6);
    Del_X_3(&h, 6);
    printList(h);
    printList2(&h);
}