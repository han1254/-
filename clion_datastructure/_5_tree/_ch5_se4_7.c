//
// Created by han1254 on 5/9/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

int get_level(BiTree tree, char data) {
    if (tree == NULL) return 0;//not find the target data node;
    if (tree->data == data) return 1;
    int res1 = get_level(tree->lchild, data);
    int res2 = get_level(tree->rchild, data);
    if (res1 > 0) return res1 + 1;
    if (res2 > 0) return res2 + 1;
    return 0;
}

int get_level2(BiTree tree, char data) {
    if (tree == NULL) return 0;
    if (tree->data == data) return 1;
    int res = tree->data > data ? get_level2(tree->lchild, data)
            : get_level2(tree->rchild, data);
    if (res == 0) return 0;
    return res + 1;
}

int get_level3(BiTree tree, char data) {
    int n = 0;
    BiTree node = tree;
    if (node != NULL) {
        n++;
        while (data != node->data) {
            if (data < node->data)
                node = node->lchild;
            else
                node = node->rchild;
            if (node == NULL) {
                printf("没有找到相关结点\n");
                return 0;
            }
            n++;
        }
    }
    return n;
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

    printf("暴力解法：找到在第%d层\n", get_level(tree1, '3'));
    printf("使用二叉排序树的性质：找到在第%d层\n", get_level2(tree1, '1'));
    printf("使用二叉排序树的性质以及非递归：找到在第%d层\n", get_level3(tree1, '8'));
}