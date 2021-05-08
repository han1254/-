//
// Created by han1254 on 5/8/21.
//
#include <memory.h>
#include "stdlib.h"
#include "_5_3_19_util.h"

/**
 * 基于先序遍历的求WPL的方法
 * 有可能是我做错了？比书上的少
 * copyright: han1254
 * @param root
 * @param depth
 * @return
 */
int wPlPre(BiTree tree, int depth) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->lchild == NULL && tree->rchild == NULL) {
        printf("%c: %d（路径） * %d（权值）\n", tree->data, depth, tree->weight);
        return depth * tree->weight;
    }
    return (wPlPre(tree->lchild, depth + 1) + wPlPre(tree->rchild, depth + 1));
}
/**
 * copyright:han1254
 * @param root
 * @return
 */
int wPl(BiTree root) {
    return wPlPre(root, 0);//注意是0，因为WPL是用路径数乘权值
}

/**
 * 王道：基于先序遍历
 * @param tree
 * @param deep
 * @return
 */
int wpl_PreOrder(BiTree tree, int deep) {
    static int wpl = 0;
    if (tree->lchild == NULL && tree->rchild == NULL)
        wpl += deep * tree->weight;
    if (tree->lchild != NULL)
        wpl_PreOrder(tree->lchild, deep + 1);
    if (tree->rchild != NULL)
        wpl_PreOrder(tree->rchild, deep + 1);
    return wpl;
}
/**
 * 王道：基于先序遍历
 * @param root
 * @return
 */
int WPL1(BiTree root) {
    return wpl_PreOrder(root, 0);
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

    setWeight(tree1, 'C', 1, 3);
    setWeight(tree1, 'E', 1, 2);
    setWeight(tree1, 'H', 1, 4);
    setWeight(tree1, 'I', 1, 1);

    printf("WPL = %d\n", wPl(tree1));

    printf("WPL（王道书：基于先序遍历）:%d\n", WPL1(tree1));
}
