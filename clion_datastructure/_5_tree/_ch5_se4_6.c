//
// Created by han1254 on 5/9/21.
//
#include <memory.h>
#include "BiTreeImpl.h"
int iSSortedBiTree(BiTree tree) {
    if (tree == NULL) return 1;
    BiTree l = tree->lchild;
    BiTree r = tree->rchild;
    if (!iSSortedBiTree(l) || !iSSortedBiTree(r)) return 0;//判断左右子树是否是排序树
    if ((l == NULL || l->data < tree->data)
    && (r == NULL || r->data > tree->data))
        return 1;
    return 0;
}

int main() {
    //         6
    //      /     \
    //    2         8
    //  /   \
    // 1     4
    //      /
    //     3
    //

    BiTree tree1 = (BiTree)malloc(sizeof(BiTree));
    char *t = "62814####3#####\n";
    GenerateTree(tree1, t, strlen(t));

    if (iSSortedBiTree(tree1))
        printf("是二叉排序树\n");
    else
        printf("不是\n");

    //         6
    //      /     \
    //    2         8
    //  /   \
    // 1     4
    //      /
    //     7
    //

    BiTree tree2 = (BiTree)malloc(sizeof(BiTree));
    char *t2 = "62814####7#####\n";
    GenerateTree(tree2, t2, strlen(t2));

    if (iSSortedBiTree(tree2))
        printf("是二叉排序树\n");
    else
        printf("不是\n");


}