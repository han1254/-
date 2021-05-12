//
// Created by han1254 on 5/12/21.
//


#include <memory.h>
#include "_5_4_12_util.h"

BCNode *Search_Small(BCNode* t,int k) {
    if (k < 1 || k > t->count) return NULL;
    if (t->lchild == NULL) {
        if (k == 1) return t;
        else return Search_Small(t->rchild, k - 1);
    } else {
        if (t->lchild->count == k - 1) return t;
        if (t->lchild->count > k - 1) return Search_Small(t->lchild, k);
        if (t->lchild->count < k - 1) return Search_Small(t->rchild, k - (t->lchild->count + 1));
    }
    return NULL;
}

int main() {
    BiCTree tree2 = (BiCTree) malloc(sizeof(BCNode));

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
    InitCount(tree2);

    printf("%c\n", Search_Small(tree2, 6)->data);

}