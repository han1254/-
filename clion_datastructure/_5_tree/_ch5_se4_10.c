//
// Created by han1254 on 5/12/21.
//

#include <memory.h>
#include "BiTreeImpl.h"
/**
 * copyright:han1254
 * 众所周知，中序遍历一棵二叉排序树，输出的是顺序的排列，我只要把中序遍历
 * 反过来，就行了呗。以前是“左中右”，现在是“右中左”
 * 这个函数是非递归实现
 * @param tree
 * @param k
 */
void printGEK(BiTree tree, char k) {
    BiTreeStack stack;
    InitTreeStack(&stack);

    BiTree ptr = tree;
    while (ptr || !StackEmpty(stack)) {
        if (ptr) {
            if (ptr->data < k) break;//如果发现结点的值小于k，则退出
            Push(&stack, ptr);
            ptr = ptr->rchild;
        } else {
            Pop(&stack, &ptr);
            printf("%c ", ptr->data);
            ptr = ptr->lchild;
        }
    }
}
/**
 * 递归实现
 * @param tree
 * @param k
 */
void printGEK_Cur(BiTree tree, char k) {
    if (tree != NULL) {
        printGEK_Cur(tree->rchild, k);
        if (tree->data < k) return;
        printf("%c ", tree->data);
        printGEK_Cur(tree->lchild, k);
    }
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
    printGEK(tree1, '2');
    printf("\n");

    BiTree tree2 = (BiTree) malloc(sizeof(BiTNode));

    //       H
    //   /       \
    //  B         J
    // /  \      / \
    //A    D    I   K
    //    / \
    //   C   F
    //      / \
    //     E   G
    char *t2 = "HBJADIK##CF##########EG########\n";
    GenerateTree(tree2, t2, strlen(t2));//可以使用这个方法直接用字符串创建树
    printGEK_Cur(tree2, 'C');
}