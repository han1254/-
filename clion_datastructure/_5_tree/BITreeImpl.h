//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_BITREEIMPL_H
#define CLION_DATASTRUCTURE_BITREEIMPL_H

#include <stdlib.h>
#include "BiTNode.h"
#include "TreeQueueImpl.h"
#include "stdio.h"
void visit(BiTree tree) {
    if (tree == NULL || tree->data == '#') {
        printf("Null node\n");
    } else {
        printf("%c ", tree->data);
    }
}

/**
 * 通过字符串方式创建树
 * @param root
 * @param s
 * @param len
 */
void GenerateTree(BiTree* root, const char* s, int len) {
    int index = 0;
    int n = 2;
    TreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, *root);
    BiTree tempTree;
    (*root)->data = s[index++];
    while (!QueueEmpty(queue) && index < len) {
        int parentCount = queue.rear - queue.front;
        for (int j = 0; j < parentCount; ++j) {
            Dequeue(&queue, &tempTree);
            BiTNode* nodeL = NULL;
            BiTNode* nodeR = NULL;
            if (tempTree != NULL) {
                if (s[index] != '#') {
                    nodeL = (BiTree)malloc(sizeof(BiTNode));
                    nodeL->data = s[index];
                }
                index++;
                if (index >= len) break;
                if (s[index] != '#') {
                    nodeR = (BiTree)malloc(sizeof(BiTNode));
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

/**
 * 通过输入的方式创建树
 * @param root
 */
void GenerateTreeByInput(BiTree* root) {
    int i = 2;
    int n = 2;
    char ch;
    TreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, *root);
    BiTree tempTree;
    printf("input root\n");
    ch = (char)getchar();
    while(getchar()!='\n');
    (*root)->data = ch;
    while (!QueueEmpty(queue)) {
        printf("Now it's %dth level, you have to enter %d nodes(enter '#' as a symbol of null)\n", i, n);
        int parentCount = queue.rear - queue.front;
        for (int j = 0; j < parentCount; ++j) {
            Dequeue(&queue, &tempTree);
            BiTNode* nodeL = NULL;
            BiTNode* nodeR = NULL;
            ch = (char)getchar();
            if (tempTree != NULL) {
                if (ch != '#') {
                    nodeL = (BiTree)malloc(sizeof(BiTNode));
                    nodeL->data = ch;
                }
                tempTree->lchild = nodeL;
            }

            ch = (char)getchar();
            if (tempTree != NULL) {
                if (ch != '#') {
                    nodeR = (BiTree)malloc(sizeof(BiTNode));
                    nodeR->data = ch;
                }
                tempTree->rchild = nodeR;
            }

            Enqueue(&queue, nodeL);
            Enqueue(&queue, nodeR);
        }
        i++;
        n *= 2;
        while(getchar()!='\n');
        printf("end the input?(y or n)\n");
        if (getchar() == 'y' || getchar() == 'Y') {
            break;
        }
    }
}

void InOrder(BiTree tree) {
    if (tree == NULL || tree->data == '#') {
        return;
    }
    InOrder(tree->lchild);
    visit(tree);
    InOrder(tree->rchild);
}

void PreOrder(BiTree tree) {
    if (tree == NULL || tree->data == '#') {
        return;
    }
    visit(tree);
    PreOrder(tree->lchild);
    PreOrder(tree->rchild);
}

void PostOrder(BiTree tree) {
    if (tree == NULL || tree->data == '#') {
        return;
    }
    PostOrder(tree->lchild);
    PostOrder(tree->rchild);
    visit(tree);
}

#endif //CLION_DATASTRUCTURE_BITREEIMPL_H
