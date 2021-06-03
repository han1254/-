//
// Created by han1254 on 6/3/21.
//

#ifndef CLION_DATASTRUCTURE_GRAPH_TRAVEL_H
#define CLION_DATASTRUCTURE_GRAPH_TRAVEL_H

#include "../_1_adjacency_matrix/MGraphImpl.h"
#include "../../_3_stack_and_queue/queue/SqQueueImpl.h"
static int visited[MAX_VERTEX_NUM];
static SqQueue queue;

void visit(int v, char* content) {
    printf("current vex: %d, content: %s\n", v, content);
}

void BFS(MGraph graph, int i);

void BFSTraverse(MGraph graph) {
    for (int i = 0; i < graph.vex_num; ++i)
        visited[i] = 0;
    InitQueue_Sq(&queue);
    for (int i = 0; i < graph.vex_num; ++i) {
        if (!visited[i])
            BFS(graph, i);
    }
}

void BFS(MGraph graph, int v) {
    visit(v, graph.vexs[v].content);
    visited[v] = 1;
    EnQueue_Sq(&queue, v);
    while (!QueueEmpty_Sq(queue)) {
        DeQueue_Sq(&queue, &v);
        for (int w = FirstNeighbor(graph, v); w >= 0; w = NextNeighbor(graph, v, w)) {
            if (!visited[w]) {
                visit(w, graph.vexs[w].content);
                visited[w] = 1;
                EnQueue_Sq(&queue, w);
            }
        }
    }
}
/**
 * BFS算法求解单源最短路径问题
 * @param G
 * @param u
 */
void BFS_MIN_Distance(MGraph G, int u) {
    int d[G.vex_num];
    int min_dis_visited[G.vex_num];
    for (int i = 0; i < G.vex_num; ++i) {
        d[i] = INFINITY;
        min_dis_visited[i] = 0;
    }

    min_dis_visited[u] = 1;
    d[u] = 0;
    SqQueue min_dis_queue;

    InitQueue_Sq(&min_dis_queue);

    EnQueue_Sq(&min_dis_queue, u);

    while (!QueueEmpty_Sq(min_dis_queue)) {
        DeQueue_Sq(&min_dis_queue, &u);
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {
            if (!min_dis_visited[w]) {
                min_dis_visited[w] = 1;
                d[w] = d[u] + 1;
                EnQueue_Sq(&min_dis_queue, w);
            }
        }
    }
    for (int i = 0; i < G.vex_num; ++i) {
        printf("%d->%d : %d\n", u, i, d[i]);
    }
}

#endif //CLION_DATASTRUCTURE_GRAPH_TRAVEL_H
