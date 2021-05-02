//
// Created by han1254 on 5/2/21.
// 王道考研数据结构2021版p149
//
#include <memory.h>
#include "BiTreeImpl.h"


int get_height(BiTree tree) {
    BiTreeQueue queue;//队列，先把每层的结点入队
    BiTreeStack stack;//栈，用栈把队列的结点先缓存起来，然后遍历这些结点，把子结点入队
    InitQueue(&queue);
    InitTreeStack(&stack);

    BiTree temp = tree;
    Enqueue(&queue, tree);
    int level = 0;
    while(!QueueEmpty(queue)) {
        while (!QueueEmpty(queue)) {
            Dequeue(&queue, &temp);
            Push(&stack, temp);
        }
        while (!StackEmpty(stack)) {
            Pop(&stack, &temp);
            if (temp->lchild != NULL)
                Enqueue(&queue, temp->lchild);
            if (temp->rchild != NULL)
                Enqueue(&queue, temp->rchild);
        }
        level++;
    }
    return level;
}

/**
 * [王道答案]
 * 感觉王道书上的解题方法很多都跟闹着玩似的，没有固定模式
 * 这里直接又把队列实现了一遍
 * 王道书不太具备考试时候的可行性
 * @param T
 */
int Btdetpth(BiTree T) {
    if (!T) {
        return 0;
    }

    int front = -1, rear = -1;//这里值得注意的是：front指向最后一个出队的结点，而不是队头
    int last = 0, level = 0;
    BiTree Q[MaxTreeQueueSize];
    Q[++rear] = T;
    BiTree p;
    while (front < rear) {
        p = Q[++front];
        if (p->lchild)
            Q[++rear] = p->lchild;
        if (p->rchild)
            Q[++rear] = p->rchild;
        if (front == last) {
            last = rear;
            level++;
        }
    }
    return level;
}
/**
 * [王道答案]
 * 递归实现
 * @param T
 */
int Btdepth2(BiTree T) {
    if (T == NULL) return 0;

    int dep1 = Btdepth2(T->lchild);
    int dep2 = Btdepth2(T->rchild);

    if (dep1 > dep2) return dep1 + 1;
    return dep2 + 1;
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

    printf("tree1's level=%d\n", get_height(tree1));

    char *t2 = "12345####67\n";
    BiTree tree2;
    tree2 = (BiTree)malloc(sizeof(BiTNode));
    GenerateTree(tree2, t2, strlen(t2));

    print_tree(tree2);

    printf("tree1's level=%d\n", get_height(tree2));


}