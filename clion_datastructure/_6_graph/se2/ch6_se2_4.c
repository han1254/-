//
// Created by han1254 on 6/2/21.
// 将一个邻接表转换成邻接矩阵
//
#include "../_2_adjacency_list/ALGraphImpl.h"

void Convert(ALGraph graph, int* arcs) {
    for (int i = 0; i < graph.vex_num; ++i) {
        ArcNode* arc = graph.vertices[i].firstarc;
        while (arc != NULL) {
            arcs[i * graph.vex_num + arc->adjvex] = 1;
            arcs[arc->adjvex * graph.vex_num + i] = 1;
            arc = arc->nextarc;
        }
    }
}

int main() {
    ALGraph alGraph;
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDG"
              ".txt", &alGraph);
    int arcs[alGraph.vex_num][alGraph.vex_num];
    for (int i = 0; i < alGraph.vex_num; ++i) {
        for (int j = 0; j < alGraph.vex_num; ++j) {
            arcs[i][j] = 0;
        }
    }
    Convert(alGraph, arcs);
    for (int i = 0; i < alGraph.vex_num; ++i) {
        for (int j = 0; j < alGraph.vex_num; ++j) {
            printf("%d ", arcs[i][j]);
        }
        printf("\n");
    }
}


