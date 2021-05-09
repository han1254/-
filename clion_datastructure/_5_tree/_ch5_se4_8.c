//
// Created by han1254 on 5/9/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

int is_balance(BiTree tree, int depth) {
    if (tree == NULL) return depth;
    depth++;
    int dep1 = is_balance(tree->lchild, depth);//左子树的深度
    int dep2 = is_balance(tree->rchild, depth);//右子树的深度
    if (dep1 == -1 || dep2 == -1) return -1;//左右子树一旦有一个不平衡，则返回-1
    if (dep1 - dep2 > 1 || dep1 - dep2 < -1) return -1;
    return dep1 > dep2 ? dep1 : dep2;
}

int judge_balance(BiTree tree) {
    if (is_balance(tree, 0) >= 0) return 1;
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


    if (judge_balance(tree1)) {
        printf("是平衡的\n");
    } else {
        printf("不是平衡的\n");
    }

    //         6
    //      /     \
    //    2         8
    //  /   \
    // 1     4   7     9
    //      /
    //     3
    //

    BiTree tree2 = (BiTree)malloc(sizeof(BiTree));
    char *t2 = "6281479##3#####\n";
    GenerateTree(tree2, t2, strlen(t));
    if (judge_balance(tree2)) {
        printf("是平衡的\n");
    } else {
        printf("不是平衡的\n");
    }
}