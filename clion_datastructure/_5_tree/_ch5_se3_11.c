//
// Created by han1254 on 5/2/21.
//
#include "BiTreeImpl.h"
#include "../../../../../../usr/include/memory.h"


void free_tree(BiTree tree) {
    if (tree) {
        free_tree(tree->lchild);
        free_tree(tree->rchild);
        free(tree);
    }
}
/**
 * @param tree
 * @param x
 */
void in_free(BiTree tree, const char x) {
    if (tree != NULL) {
        BiTree lchild = tree->lchild;
        BiTree rchild = tree->rchild;
        if (lchild != NULL && lchild->data == x) tree->lchild = NULL;
        if (rchild != NULL && rchild->data == x) tree->rchild = NULL;
        in_free(lchild, x);
        in_free(rchild, x);
        if (tree->data == x) {
            free_tree(tree);
        }

    }
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
    in_free(tree1, '*');

    print_tree(tree1);
}