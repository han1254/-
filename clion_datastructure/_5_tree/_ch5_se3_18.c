//
// Created by han1254 on 5/7/21.
//

#include <memory.h>
#include "ThreadTreeImpl.h"
#include "_5_3_18_util.h"

ThreadTree InPostPre(ThreadTree p) {
    ThreadTree q;
    if (p->rtag == 0) {
        q = p->rchild;
    } else if (p->ltag == 0) {
        q = p->lchild;
    } else if (p->lchild == NULL) {
        q = NULL;
    } else {
        while(p->ltag == 1 && p->lchild != NULL)
            p = p->lchild;
        if (p->ltag == 0)
            q = p->lchild;
        else
            q = NULL;
    }
    return q;
}

int main() {
    ThreadTree tree1 = (ThreadTree) malloc(sizeof(ThreadNode));
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

    CreateInThread(tree1);
    ThreadTree res = find(tree1, 'e', 1);
    ThreadTree pre = InPostPre(res);
    printf("%c\n", pre->data);
}