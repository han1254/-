//
// Created by han1254 on 5/2/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

/**
 * copyright:han1254
 * @param b
 */
void swap(BiTree b) {
    if (b == NULL) return;
    BiTree node = b->lchild;
    b->lchild = b->rchild;
    b->rchild = node;
    swap(b->lchild);
    swap(b->rchild);
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
    printf("交换前:\n");
    print_tree(tree1);
    swap(tree1);
    printf("交换后:\n");
    print_tree(tree1);
}