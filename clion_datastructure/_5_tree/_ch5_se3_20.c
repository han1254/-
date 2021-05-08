//
// Created by han1254 on 5/8/21.
//

#include <memory.h>
#include "_5_3_20_util.h"

/**
 * han1254
 * @param root
 * @param isRoot 根节点不需要打印括号
 */
void print_in_with_pa(BTree* root, int isRoot) {
    if (root == NULL) return;
    int hasParent = (root->lchild != NULL || root->rchild != NULL) ? 1 : 0;
    if (hasParent && !isRoot) printf("(");
    print_in_with_pa(root->lchild, 0);
    printf("%s",root->data);
    print_in_with_pa(root->rchild, 0);
    if (hasParent && !isRoot) printf(")");
}


int main() {
    //         +
    //      /     \
    //    *         -
    //  /   \         \
    // b     a         -
    //                /  \
    //               c    d

    BTree *tree1 = (BTree*) malloc(sizeof(BTree));
    char *t = "+*-ab#-######cd\n";
    GenerateTree(tree1, t, strlen(t));
    print_tree(tree1);
    print_in_with_pa(tree1, 1);

    printf("\n");

    BTree *tree2 = (BTree*) malloc(sizeof(BTree));
    char *t2 = "*+*abc-#######d\n";
    GenerateTree(tree2, t2, strlen(t));
    print_tree(tree2);
    print_in_with_pa(tree2, 1);

}
