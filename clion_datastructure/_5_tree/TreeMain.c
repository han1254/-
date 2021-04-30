//
// Created by han1254 on 4/30/21.
//

#include <memory.h>
#include "BITreeImpl.h"

int main() {
    BiTree tree = (BiTree)malloc(sizeof(BiTNode));

    //     a
    //  b      c
    //e  #   f   #
    //    GenerateTree(&tree, "abce#f#", 7);


    //数据结构课本p129例子
//    char* t = "-+/a*ef##b-##########cd########\n";
//    GenerateTree(&tree, t, strlen(t));//可以使用这个方法直接用字符串创建树
    GenerateTreeByInput(&tree);//也可以手动输入创建
    InOrder(tree);
    printf("\n");
    PreOrder(tree);
    printf("\n");
    PostOrder(tree);
}