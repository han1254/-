//
// Created by han1254 on 4/29/21.
// 求编号分别为i 和 j的两个节点的最近的公共祖先的节点
//

#include "SqBiTree.h"
#include "stdio.h"

/**
* 王道书上是从1开始，我这里是从0开始
* 如果从0开始的话，节点i的左子树为2*i+1，右子树为2*i + 2
* 其双亲节点为i/2(i为奇数）或 (i-1)/2（i为偶数）
* @param tree
* @param i
* @param j
* @return
*/
int CommonAncestor(const SqBiTree tree, int i, int j) {
    if (tree[i] != '#' && tree[j] != '#') {
        while (i != j) {
            if (i > j) {
                i = (i - i % 2 == 0 ? 1 : 0) / 2;
            } else {
                j = (j - j % 2 == 0 ? 1 : 0) / 2;
            }
        }
    }
    return i;
}

/**
 *        A
 *      /  \
 *    B     C
 *   / \   / \
 *  D   E F   G(6)
 * /
 *H(7)
 * @return 应该返回0
 */
int main() {
    SqBiTree tree;
    InitSqTree(tree);
//    printf("input number of tree node\n");
//    int n;
//    scanf("%d", &n);
//    getchar();
//    for (int i = 0; i < n; ++i) {
//        printf("input position and content\n");
//        int pos;
//        scanf("%d", &pos);
//        getchar();
//        char content = (char)getchar();
//        AddTreeNode(pos, content, tree);
//    }

    for (int i = 0; i < 8; ++i) {
        AddTreeNode(i, (char)((int)'A' + i), tree);
    }
    PrintTree(tree);
    printf("%d\n", CommonAncestor(tree, 6, 7));
}
