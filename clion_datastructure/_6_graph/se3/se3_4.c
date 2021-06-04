//
// Created by han1254 on 6/4/21.
// 判断i到j是否有路径
//
#include "../_2_adjacency_list/ALGraphImpl.h"
int* visited;
int Exist_Path_DFS(ALGraph g, int i, int j) {
    if (i == j) return 1;
    visited[i] = 1;
    for (int p = FirstNeighbor(g, i); p >= 0; p = NextNeighbor(g, i, p)) {
        if (!visited[p] && Exist_Path_DFS(g, p, j)) return 1;
    }
    return 0;
}
int main() {
    ALGraph graph;
    // 0->1->2->3
    // 1->3
    // 2
    // 3
    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/se3/se3_4_data.txt", &graph);
    visited = (int*)malloc(sizeof(int) * graph.vex_num);

    for (int i = 0; i < graph.vex_num; ++i)
        visited[i] = 0;
    if (Exist_Path_DFS(graph, 2, 3))
        printf("存在从2到3的路径\n");
    else
        printf("不存在从2到3的路径\n");

    if (Exist_Path_DFS(graph, 0, 3))
        printf("存在从0到3的路径\n");
    else
        printf("不存在从0到3的路径\n");
}