//
// Created by han1254 on 5/2/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

/**
 * copyright:han1254
 * @param tree
 * @param res
 * @param index 用一个指针记录遍历的个数
 * @param k
 */
void find_pre_k(BiTree tree, char* res, int* index, int k) {
    if (tree == NULL) return;
    (*index)++;
    if (*index == k) {
        *res = tree->data;
        return;
    };
    if (*index > k) return;
    find_pre_k(tree->lchild, res, index, k);
    find_pre_k(tree->rchild, res, index, k);
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
    char res;
    int index = 0;

    find_pre_k(tree1, &res, &index, 4);

    printf("find: %c", res);
}