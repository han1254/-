//
// Created by han1254 on 5/9/21.
//
#include <memory.h>
#include "BiTreeImpl.h"
void findMinMax(BiTree ltree, BiTree rtree, char* max, char* min) {
    if (ltree == NULL && rtree == NULL) return;
    if (ltree != NULL && ltree->lchild == NULL) *min = ltree->data;
    if (rtree != NULL && rtree->rchild == NULL) *max = rtree->data;
    findMinMax(ltree == NULL ? ltree : ltree->lchild,
               rtree == NULL ? rtree : rtree->rchild, max, min);
}

void minMax(BiTree tree, char* max, char* min) {
    findMinMax(tree, tree, max, min);
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

    char max, min;
    minMax(tree1, &max, &min);

    printf("max:%c, min:%c\n", max, min);
}