//
// Created by han1254 on 4/30/21.
//

#include "BITreeImpl.h"

int main() {
    BiTree tree = (BiTree)malloc(sizeof(BiTNode));

    //     a
    //  b      c
    //e  #   f   #
    GenerateTreeByStr(&tree, "abce#f#", 7);
    InOrder(tree);
    printf("\n");
    PreOrder(tree);
    printf("\n");
    PostOrder(tree);
}