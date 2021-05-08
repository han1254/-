//
// Created by han1254 on 5/7/21.
//
#include <memory.h>
#include "BiTreeImpl.h"
/**
 *
 * @param tree
 * @return
 */
int max_width(BiTree tree) {
    BiTreeQueue queue;
    InitQueue(&queue);
    Enqueue(&queue, tree);
    BiTree temp = tree;
    int count = 1, max = 1;//count 记录每层的子树数量
    while (!QueueEmpty(queue)) {
        int m = count;
        count = 0;
        for (int i = 0; i < m; ++i) {
            Dequeue(&queue, &temp);
            if (temp->lchild != NULL) {
                count++;
                Enqueue(&queue, temp->lchild);
            }
            if (temp->rchild != NULL) {
                count++;
                Enqueue(&queue, temp->rchild);
            }
        }
        if (count > max) max = count;
    }

    return max;
}

int main() {
    //         A
    //      /     \
    //    B         D
    //      \     /   \
    //       C   E     F
    //                /  \
    //               G    I
    //                \
    //                 H
    BiTree tree1 = (BiTree) malloc(sizeof(BiTNode));
    char *t = "ABD#CEF######GI#############H##\n";
    GenerateTree(tree1, t, strlen(t));
    print_tree(tree1);

    BiTree tree2 = (BiTree) malloc(sizeof(BiTNode));
    //数据结构课本p129例子
    //       -
    //   /       \
    //  +         /
    // /  \      / \
    //a    *    e   f
    //    / \
    //    b  -
    //      / \
    //     c   d
    char *t1 = "-+/a*ef##b-##########cd########\n";
    GenerateTree(tree2, t1, strlen(t1));//可以使用这个方法直接用字符串创建树
    printf("max width1:%d\n", max_width(tree1));
    printf("max width2:%d\n", max_width(tree2));
}