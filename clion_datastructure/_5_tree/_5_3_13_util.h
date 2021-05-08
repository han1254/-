//
// Created by han1254 on 5/7/21.
//

#ifndef CLION_DATASTRUCTURE__5_3_13_UTIL_H
#define CLION_DATASTRUCTURE__5_3_13_UTIL_H

#include <stddef.h>
#include "BiTree.h"
/**
 * 查找指定内容的结点
 * @param data
 * @param n 在先序的第几个（有可能有的结点重复）
 * @return
 */
BiTree find(BiTree tree, char data, int n) {
    if (tree == NULL || n == 0) return NULL;
    if (tree->data == data) {
        if (n == 1)
            return tree;
        else
            n = n - 1;
    }

    BiTree res1 = find(tree->lchild, data, n);
    if (res1 != NULL) return res1;
    return find(tree->rchild, data, n);
}
#endif //CLION_DATASTRUCTURE__5_3_13_UTIL_H
