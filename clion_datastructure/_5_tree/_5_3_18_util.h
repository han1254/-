//
// Created by han1254 on 5/7/21.
//

#ifndef CLION_DATASTRUCTURE__5_3_18_UTIL_H
#define CLION_DATASTRUCTURE__5_3_18_UTIL_H

#include <stddef.h>
#include "ThreadTree.h"
ThreadTree find(ThreadTree tree, char data, int n) {
    if (tree == NULL || n == 0) return NULL;
    if (tree->data == data) {
        if (n == 1)
            return tree;
        else
            n = n - 1;
    }

    ThreadTree res1 = find(tree->ltag == 1 ? NULL : tree->lchild, data, n);
    if (res1 != NULL) return res1;
    return find(tree->rtag == 1 ? NULL : tree->rchild, data, n);
}

#endif //CLION_DATASTRUCTURE__5_3_18_UTIL_H
