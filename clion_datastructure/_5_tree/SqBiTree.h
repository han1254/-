//
// Created by han1254 on 4/29/21.
//

#ifndef CLION_DATASTRUCTURE_SQBITREE_H
#define CLION_DATASTRUCTURE_SQBITREE_H

#include <memory.h>
#include "stdio.h"
#define MAX_TREE_SIZE 100
typedef char SqBiTree[MAX_TREE_SIZE];

void InitSqTree(SqBiTree tree) {
    memset(tree, '#', MAX_TREE_SIZE);
}

void PrintTree(SqBiTree tree) {
    for (int i = 0; i < MAX_TREE_SIZE; ++i) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

void AddTreeNode(int index, char c, SqBiTree tree) {
    tree[index] = c;
}


#endif //CLION_DATASTRUCTURE_SQBITREE_H
