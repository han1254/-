//
// Created by han1254 on 5/7/21.
//

#include <memory.h>
#include "BiTreeImpl.h"
static BiTree head = NULL;
void InOrderLink(BiTree bt, BiTree* pre) {
    if (bt) {
        InOrderLink(bt->lchild, pre);
        if (bt->lchild == NULL && bt->rchild == NULL) {
            if (*pre == NULL) {
                head = bt;
                *pre = bt;
            }
            else {
                (*pre)->rchild = bt;
                *pre = bt;
            }
        }
        InOrderLink(bt->rchild, pre);
        (*pre)->rchild = NULL;
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
    BiTree pre = (BiTree)malloc(sizeof(BiTNode));
    pre = NULL;
    InOrderLink(tree1, &pre);

    BiTree node = head;
    while (node != NULL) {
        printf("%c->", node->data);
        node = node->rchild;
    }
    printf("NULL\n");
}