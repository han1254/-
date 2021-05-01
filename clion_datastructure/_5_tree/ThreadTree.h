//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_THREADTREE_H
#define CLION_DATASTRUCTURE_THREADTREE_H
#include "BiTree.h"
typedef struct ThreadNode {
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;//ltag:0 lchid指向左孩子；ltag:1 lchild指向右孩子;
    //rtag:0 lchild指向左孩子；rtag:1 rtag指向右孩子
}ThreadNode, *ThreadTree;

#endif //CLION_DATASTRUCTURE_THREADTREE_H
