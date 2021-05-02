//
// Created by han1254 on 5/2/21.
//
#include <memory.h>
#include "BiTreeImpl.h"
/**
 * 获得前序遍历根结点在中序遍历的位置
 * 注意，目前这种解法只能解决子结点不重复的树
 * 王道书上的也是如此
 * @param t
 * @param B
 * @param n
 * @return
 */
int get_pos(char t, const char B[], int n) {
    for (int i = 0; i < n; ++i) {
        if (B[i] == t) return i;
    }
    return -1;
}

BiTree build(const char A[], const char B[], int n,
             int pre_root, int in_left, int in_right) {
    if (in_left > in_right) return NULL;
    int in_root = get_pos(A[pre_root], B, n);
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[pre_root];
    root->lchild = build(A, B, n, pre_root + 1, in_left, in_root - 1);//关键在这两行，如何计算先序根的位置
    root->rchild = build(A, B, n, pre_root + in_root - in_left + 1, in_root + 1, in_right);
    return root;
}

BiTree rebuild(const char A[], const char B[], int n) {
    return build(A, B, n, 0, 0, n - 1);
}

int main() {
    char* in = "BCAEDGHFI";
    char* pre = "ABCDEFGHI";

    BiTree tree = rebuild(pre, in, 9);
    print_tree(tree);

    PreOrder_Iter(tree);
    printf("\n");
    InOrder_Iter(tree);
    printf("\n");
    PostOrder_Iter(tree);
    printf("\n");

    LevelOrder(tree);
}