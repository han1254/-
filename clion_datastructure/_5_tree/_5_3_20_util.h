//
// Created by han1254 on 5/8/21.
//

#ifndef CLION_DATASTRUCTURE__5_3_20_UTIL_H
#define CLION_DATASTRUCTURE__5_3_20_UTIL_H
#define MaxTreeQueueSize 100
#include <stdlib.h>
#include "stdio.h"
typedef struct node {
    char data[10];
    struct node *lchild, *rchild;
}BTree, *BiTree;
typedef struct {
    BiTree queue[MaxTreeQueueSize];
    int front, rear;
} BiTreeQueue;

void print_liner_tree(BiTree tree, int level) {
    if (tree == NULL) return;

    for (int i = 0; i < level; ++i) {
        printf("|");
    }
    printf("[%c]\n", tree->data[0]);

    print_liner_tree(tree->lchild, level+1);
    print_liner_tree(tree->rchild, level+1);
}

void print_tree(BiTree tree) {
    print_liner_tree(tree, 1);
}

void InitQueue(BiTreeQueue* queue) {
    queue->rear = queue->front = 0;
}

int Enqueue(BiTreeQueue* queue, BiTree node) {
    if ((queue->rear + 1) % MaxTreeQueueSize == queue->front) {
        printf("Queue is full\n");
        return 0;
    }
    queue->queue[queue->rear] = node;
    queue->rear = (queue->rear + 1) % MaxTreeQueueSize;
    return 1;
}

int Dequeue(BiTreeQueue* queue, BiTree* res) {
    if (queue->rear == queue->front) {
        printf("Queue is empty\n");
        return 0;
    }
    *res = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MaxTreeQueueSize;
    return 1;
}

int QueueEmpty(BiTreeQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}
/**
 * 通过字符串方式创建树
 * @param root
 * @param s
 * @param len
 */
void GenerateTree(BiTree root, const char *s, int len) {
    int index = 0;
    int n = 2;
    BiTreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, root);
    BiTree tempTree;
    root->data[0] = s[index++];
    while (!QueueEmpty(queue) && index < len) {
        int parentCount = queue.rear - queue.front;
        for (int j = 0; j < parentCount; ++j) {
            Dequeue(&queue, &tempTree);
            BTree *nodeL = NULL;
            BTree *nodeR = NULL;
            if (tempTree != NULL) {
                if (s[index] != '#') {
                    nodeL = (BiTree) malloc(sizeof(BTree));
                    nodeL->data[0] = s[index];
                }
                index++;
                if (index >= len) break;
                if (s[index] != '#') {
                    nodeR = (BiTree) malloc(sizeof(BTree));
                    nodeR->data[0] = s[index];
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

//void GenerateTree2(BTree* root, const char *s, int len) {
//    int index = 0;
//    int n = 2;
//    BiTreeQueue queue;
//    InitQueue(&queue);
//    Enqueue(&queue, root);
//    BiTree tempTree;
//    root->data[0] = s[index++];
//    while (!QueueEmpty(queue) && index < len) {
//        int parentCount = queue.rear - queue.front;
//        for (int j = 0; j < parentCount; ++j) {
//            Dequeue(&queue, &tempTree);
//            BTree *nodeL = NULL;
//            BTree *nodeR = NULL;
//            if (tempTree != NULL) {
//                if (s[index] != '#') {
//                    nodeL = (BTree*) malloc(sizeof(BTree));
//                    nodeL->data[0] = s[index];
//                }
//                index++;
//                if (index >= len) break;
//                if (s[index] != '#') {
//                    nodeR = (BTree*) malloc(sizeof(BTree));
//                    nodeR->data[0] = s[index];
//                }
//                index++;
//                tempTree->lchild = nodeL;
//                tempTree->rchild = nodeR;
//            } else {
//                index += 2;
//            }
//            Enqueue(&queue, nodeL);
//            Enqueue(&queue, nodeR);
//        }
//        n *= 2;
//    }
//}



#endif //CLION_DATASTRUCTURE__5_3_20_UTIL_H
