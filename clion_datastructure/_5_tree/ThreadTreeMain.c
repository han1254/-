//
// Created by han1254 on 5/1/21.
//
#include "ThreadTreeImpl.h"
int main() {
    ThreadTree tree;
    tree = (ThreadTree)malloc(sizeof(ThreadNode));
    GenerateTree(tree, "abfcd##", 7);
    CreateInThread(tree);
    InOrder(tree);
}