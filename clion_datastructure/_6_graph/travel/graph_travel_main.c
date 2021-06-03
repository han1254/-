//
// Created by han1254 on 6/3/21.
//
#include "graph_travel.h"
int main() {
    MGraph graph;
    //此图构建的是王道书上的例子
    //       a(0)
    //     /    \
    //   b(1)    c(2)
    //  / \     / \
    // d(3)e(4)f(5)g(6)
    //      \
    //       h(7)
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/travel/udg.txt", &graph);
    BFSTraverse(graph);
    DFSTraverse(graph);

    BFS_MIN_Distance(graph, 0);
}