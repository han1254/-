//
// Created by han1254 on 5/7/21.
// 找到两个结点的最近的公共祖先
// leetcode上面有这个题
//

#include <memory.h>
#include "BiTreeImpl.h"
#include "_5_3_13_util.h"

void ANCESTOR(BiTree ROOT, BiTree p, BiTree q, BiTree* r) {
    if (ROOT == NULL) {
        *r = NULL;
        return;
    }
    if (ROOT == p || ROOT == q) {
        *r = ROOT;
        return;
    }
    ANCESTOR(ROOT->lchild, p, q, r);
    BiTree l1 = *r;
    ANCESTOR(ROOT->rchild, p, q, r);
    BiTree l2 = *r;
    if (l1 != NULL && l2 != NULL)
        *r = ROOT;
    else if (l1 != NULL)
        *r = l1;
    else
        *r = l2;
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
    BiTree re1 = find(tree1, 'c', 1);
    BiTree re2 = find(tree1, 'f', 1);
    BiTree res;
    res = (BiTree)malloc(sizeof(BiTNode));
    ANCESTOR(tree1, re1, re2, &res);
    if (res == NULL)
        printf("no\n");
    else
        printf("%c\n", res->data);
}