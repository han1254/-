//
// Created by han1254 on 5/2/21.
//
#include <memory.h>
#include "BiTreeImpl.h"

/**
 * 题目灵感来源选择题第5题
 * 若m是n的祖先，则使用（后序遍历）可以找到从m到n的路径
 * @param tree
 * @param x
 * @return
 */
int post_travel(BiTree tree, char x) {
    if (tree == NULL) return 0;
    if (tree->data == x) {//若访问到了x结点，则目前程序的方法栈中存入的一定是
        //他的祖先结点，直接开始弹出，就可以了
        return 1;
    }
    int res1 = post_travel(tree->lchild, x);


    if (res1 == 1) {//说明下面的子孙已经遍历到了x结点，不必再往下走了
        visit(tree);
        return 1;
    }

    int res2 = post_travel(tree->rchild, x);
    if (res2 == 1) {//同理
        visit(tree);
        return 1;
    }
    return 0;
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
    post_travel(tree1, 'b');
}