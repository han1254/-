//
// Created by han1254 on 5/2/21.
//

#include <memory.h>
#include "BiTreeImpl.h"


void invert_level(BiTree tree) {
    BiTreeQueue queue;
    BiTreeStack stack;
    InitQueue(&queue);
    InitTreeStack(&stack);
    BiTree temp = tree;
    Enqueue(&queue, tree);
    while(!QueueEmpty(queue)) {
        while (!QueueEmpty(queue)) {
            Dequeue(&queue, &temp);
            Push(&stack, temp);
            if (temp->lchild != NULL)
                Enqueue(&queue, temp->lchild);
            if (temp->rchild != NULL)
                Enqueue(&queue, temp->rchild);
        }
        while (!StackEmpty(stack)) {
            Pop(&stack, &temp);
            printf("%c", temp->data);
        }
    }
}


int main() {

    BiTree tree1 = (BiTree)malloc(sizeof(BiTNode));
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
    char* t = "-+/a*ef##b-##########cd########\n";
    GenerateTree(tree1, t, strlen(t));//可以使用这个方法直接用字符串创建树

    invert_level(tree1);
}