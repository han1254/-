//
// Created by han1254 on 5/12/21.
//

#ifndef CLION_DATASTRUCTURE__5_4_12_UTIL_H
#define CLION_DATASTRUCTURE__5_4_12_UTIL_H

#include <stdlib.h>
#include "BCTree.h"


/**
 * 通过字符串方式创建树
 * @param root
 * @param s
 * @param len
 */
void GenerateTree(BiCTree root, const char *s, int len) {
    int index = 0;
    int n = 2;
    BiCTreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, root);
    BiCTree tempTree;
    root->data = s[index++];
    while (!QueueEmpty(queue) && index < len) {
        int parentCount = queue.rear - queue.front;
        for (int j = 0; j < parentCount; ++j) {
            Dequeue(&queue, &tempTree);
            BiCTree nodeL = NULL;
            BiCTree nodeR = NULL;
            if (tempTree != NULL) {
                if (s[index] != '#') {
                    nodeL = (BiCTree) malloc(sizeof(BCNode));
                    nodeL->data = s[index];
                }
                index++;
                if (index >= len) break;
                if (s[index] != '#') {
                    nodeR = (BiCTree) malloc(sizeof(BCNode));
                    nodeR->data = s[index];
                }
                index++;
                tempTree->lchild = nodeL;
                tempTree->rchild = nodeR;
            } else {
                index += 2;
            }
            Enqueue(&queue, nodeL);
            Enqueue(&queue, nodeR);
        }
        n *= 2;
    }
}

int Init(BiCTree tree) {
    if (tree == NULL) return 0;
    int count = Init(tree->lchild) + Init(tree->rchild) + 1;
    tree->count = count;
    return count;
}
/**
 * 初始化count值
 * @param tree
 */
void InitCount(BiCTree tree) {
    Init(tree);
}

#endif //CLION_DATASTRUCTURE__5_4_12_UTIL_H
