//
// Created by han1254 on 6/4/21.
// 图的深度优先搜素DFS算法的非递归算法（邻接表形式）
//

#include "../_2_adjacency_list/ALGraphImpl.h"
#include "../../_3_stack_and_queue/stack/SqStackImpl.h"

void visit(int i) {
    printf("%d\n", i + 1);
}

void DFS_Non_RC(ALGraph G, int v) {
    int k;
    int visited[G.vex_num];
    SqStack stack;
    InitStack(&stack);
    for (int i = 0; i < G.vex_num; ++i)
        visited[i] = 0;
    Push(&stack, v);
    visited[v] = 1;
    while (!StackEmpty(stack)) {
        Pop(&stack, &k);
        visit(k);
        for (int w = FirstNeighbor(G, k); w >= 0; w = NextNeighbor(G, k, w)) {
            if (!visited[w]) {
                Push(&stack, w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    ALGraph graph;
    //王道课本这一节的第一道大题的那个邻接矩阵
    // 1->2->3->4
    // 2->1->3->4->5
    // 3->1->2->4
    // 4->1->2->3->5
    // 5->2->4
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/se3/se3_3_data.txt", &graph);


    printALGraph(graph, UDG);


    DFS_Non_RC(graph, 0);

}