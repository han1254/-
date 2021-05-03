//
// Created by han1254 on 5/2/21.
//

#include "BiTreeImpl.h"
#include "../../../../../../usr/include/memory.h"

/**
 * copyright:han1254
 * @param tree
 * @return
 */
int DsonNode(BiTree tree) {
    if (tree == NULL) return 0;
    if (tree->lchild != NULL && tree->rchild != NULL)
        return 1 + DsonNode(tree->lchild) + DsonNode(tree->rchild);
    return DsonNode(tree->lchild) + DsonNode(tree->rchild);
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

    printf("二叉结点：%d 个\n", DsonNode(tree1));
}