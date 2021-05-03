//
// Created by han1254 on 5/2/21.
//

#include <memory.h>
#include "BiTreeImpl.h"
/**
 * copyright:han1254
 * @param T
 * @return
 */
int IsComplete(BiTree T) {
    BiTreeQueue queue;
    InitQueue(&queue);
    BiTree temp = T;
    Enqueue(&queue, T);
    int count = 1;
    while (!QueueEmpty(queue)) {
        int m = count;
        count = 0;
        for (int i = 0; i < m; ++i) {
            Dequeue(&queue, &temp);
            if (temp->lchild != NULL) {
                if (i > 0 && count == 0) return 0;//i>0说明在上一层父亲结点的非第一位
                Enqueue(&queue, temp->lchild);
                count++;
            }
            if (temp->rchild != NULL) {
                if (i > 0 && count == 0) return 0;//i>0说明在上一层父亲结点的非第一位
                Enqueue(&queue, temp->rchild);
                count++;
            }

        }
    }
    return 1;
}

int main() {
    BiTree tree1 = (BiTree) malloc(sizeof(BiTNode));
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
    char *t = "-+/a*ef##b-##########cd########\n";
    GenerateTree(tree1, t, strlen(t));//可以使用这个方法直接用字符串创建树

    if (IsComplete(tree1)) {
        printf("tree1是完全二叉树\n");
    } else {
        printf("tree1不是完全二叉树\n");
    }

    BiTree tree2;
    tree2 = (BiTree)malloc(sizeof(BiTNode));
    char *t2 = "abcdefghigklmno\n";
    GenerateTree(tree2, t2, strlen(t));//可以使用这个方法直接用字符串创建树

    if (IsComplete(tree2)) {
        printf("tree2是完全二叉树\n");
    } else {
        printf("tree2不是完全二叉树\n");
    }

}