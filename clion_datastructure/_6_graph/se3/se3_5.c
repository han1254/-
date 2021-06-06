//
// Created by han1254 on 6/4/21.
// 输出i和j之间所有的简单路径，图用邻接表表示
//
#include "../_2_adjacency_list/ALGraphImpl.h"

void printPath(int* path, int d) {
    printf("路径：\n");
    for (int i = 0; i <= d; ++i) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int* visited;


void find(ALGraph G, int u, int v, int* path, int d) {
    int w;
    ArcNode* p;
    d++;
    path[d] = u;
    visited[u] = 1;
    if (u == v)
        printPath(path, d);
    p = G.vertices[u].firstarc;
    while (p != NULL) {
        w = p->adjvex;
        if (!visited[w]) find(G, w, v, path, d);
        p = p->nextarc;
    }
    visited[u] = 0;
}

void FindPath(ALGraph G, int u, int v, int* path) {
    find(G, u, v, path, -1);
}
int main() {
    ALGraph graph;
    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/se3/se3_5_data.txt", &graph);
    visited = (int*)malloc(graph.vex_num * sizeof(int));
    printALGraph(graph, DG);
    for (int i = 0; i < graph.vex_num; ++i) {
        visited[i] = 0;
    }
    int path[graph.vex_num];
    FindPath(graph, 0, 4, path);
}