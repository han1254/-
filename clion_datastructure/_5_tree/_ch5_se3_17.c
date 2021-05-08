//
// Created by han1254 on 5/7/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

int IsSimilar(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) return 1;
    if (T1 == NULL || T2 == NULL) return 0;

    return IsSimilar(T1->lchild, T2->lchild)
    && IsSimilar(T1->rchild, T2->rchild);
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

    BiTree tree2 = (BiTree) malloc(sizeof(BiTNode));
    char *t2 = "&&&A&EF##B&##########cd########\n";
    GenerateTree(tree2, t2, strlen(t2));//可以使用这个方法直接用字符串创建树

    if (IsSimilar(tree1, tree2)) {
        printf("相似\n");
    } else {
        printf("不相似\n");
    }
}