//
// Created by han1254 on 5/27/21.
//

#include "../_1_adjacency_matrix//MGraphImpl.h"
void DFS(MGraph g, int v, int* vNum, int* eNum, int visited[]) {
    visited[v] = 1;
    (*vNum)++;
    int w = FirstNeighbor(g, v);

    while (w != -1) {
        (*eNum)++;
        if (!visited[w])
            DFS(g, w, vNum, eNum, visited);
        w = NextNeighbor(g, v, w);
    }

}
int isTree(MGraph g) {
    int visited[100];
    for (int i = 0; i < g.vex_num; ++i)
        visited[i] = 0;

    int vNum = 0, eNum = 0;
    DFS(g, 0, &vNum, &eNum, visited);
    if (vNum == g.vex_num && eNum == 2 * (g.vex_num - 1))
        return 1;
    return 0;
}


int main() {
    MGraph graph;
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/se3/se3_2_data.txt", &graph);
    showUDG(graph);
    if (isTree(graph)) printf("是Tree\n");
    else printf("不是树\n");

    MGraph UDG;
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDG.txt", &UDG);
    showUDG(UDG);
    if (isTree(UDG)) printf("是Tree\n");
    else printf("不是Tree\n");
}
