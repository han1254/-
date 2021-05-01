//
// Created by han1254 on 4/30/21.
//

#ifndef CLION_DATASTRUCTURE_THREADTREEIMPL_H
#define CLION_DATASTRUCTURE_THREADTREEIMPL_H
#include "ThreadTree.h"
#include "ThreadTreeQueue.h"
#include "stdlib.h"
/**
 * 通过字符串方式创建树
 * @param root
 * @param s
 * @param len
 */
void GenerateTree(ThreadTree root, const char* s, int len) {
    int index = 0;
    int n = 2;
    ThreadTreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, root);
    ThreadTree tempTree;
    root->data = s[index++];
    while (!QueueEmpty(queue) && index < len) {
        int parentCount = queue.rear - queue.front;
        for (int j = 0; j < parentCount; ++j) {
            Dequeue(&queue, &tempTree);
            ThreadTree nodeL = NULL;
            ThreadTree nodeR = NULL;
            if (tempTree != NULL) {
                if (s[index] != '#') {
                    nodeL = (ThreadTree)malloc(sizeof(ThreadNode));
                    nodeL->data = s[index];
                }
                index++;
                if (index >= len) break;
                if (s[index] != '#') {
                    nodeR = (ThreadTree)malloc(sizeof(ThreadNode));
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
 * 迭代创建线索
 * @param cur
 * @param pre
 */
void InThread(ThreadTree* cur, ThreadTree* pre) {
    if (*cur != NULL) {
        InThread(&(*cur)->lchild, pre);
        if ((*cur)->lchild == NULL) {//最左边的叶子节点没有前驱，因为他就是第一个被访问的
            (*cur)->ltag = 1;
            (*cur)->lchild = *pre;//如果此时cur为最左节点，那么pre为空
        }

        if (*pre != NULL && (*pre)->rchild == NULL) {
            (*pre)->rchild = *cur;
            (*pre)->rtag = 1;
        }
        *pre = *cur;
        InThread(&(*cur)->rchild, pre);
    }
}

/**
 * 中序化线索二叉树
 * @param tree
 */
void CreateInThread(ThreadTree tree) {
    ThreadTree pre = NULL;
    if (tree != NULL) {
        InThread(&tree, &pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
/**
 * 获得第一个需要遍历的节点
 * @param root
 * @return
 */
ThreadTree FirstNode(ThreadTree root) {
    while (root->ltag == 0) root = root->lchild;
    return root;
}

ThreadTree NextNode(ThreadTree tree) {
    if (tree->rtag == 0) return FirstNode(tree->rchild);
    return tree->rchild;
}

/**
 * 中序遍历线索二叉树
 * @param root
 */
void InOrder(ThreadTree root) {
    for (ThreadTree p = FirstNode(root); p != NULL; p = NextNode(p)) {
        printf("%c ", p->data);
    }
    printf("\n");
}

#endif //CLION_DATASTRUCTURE_THREADTREEIMPL_H
