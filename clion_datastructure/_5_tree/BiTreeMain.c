//
// Created by han1254 on 4/30/21.
//

#include <memory.h>
#include "BiTreeImpl.h"

int main() {
    BiTree tree = (BiTree)malloc(sizeof(BiTNode));

    //     a
    //  b      c
    //e  #   f   #
    //    GenerateTree(&tree, "abce#f#", 7);


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
    char* t = "-+/a*ef##b-##########cd########\n";
    GenerateTree(tree, t, strlen(t));//可以使用这个方法直接用字符串创建树
//    GenerateTreeByInput(&tree);//也可以手动输入创建
    InOrder(tree);
    printf("\n");
    PreOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    InOrder_Iter(tree);
    printf("\n");
    PreOrder_Iter(tree);
    printf("\n");
    PostOrder_Iter(tree);
    printf("\n");
    LevelOrder(tree);

//    puttree(tree, 5);
    printf("\n");
    print_liner_tree(tree, 1);

    PreOrder_Iter(tree);
    printf("\n");
    PreOrder_Iter_Simple(tree);
}