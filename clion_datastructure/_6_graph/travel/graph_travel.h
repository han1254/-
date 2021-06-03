//
// Created by han1254 on 6/3/21.
//

#ifndef CLION_DATASTRUCTURE_GRAPH_TRAVEL_H
#define CLION_DATASTRUCTURE_GRAPH_TRAVEL_H

#include "../_1_adjacency_matrix/MGraphImpl.h"
#include "../../_3_stack_and_queue/queue/SqQueueImpl.h"
static int bfs_visited[MAX_VERTEX_NUM];
static SqQueue bfs_queue;
static int dfs_visited[MAX_VERTEX_NUM];
static SqQueue dfs_queue;
void visit(int v, char* content) {
    printf("current vex: %d, content: %s\n", v, content);
}

void BFS(MGraph graph, int i);

void DFS(MGraph g, int i);

void BFSTraverse(MGraph graph) {
    printf("广度优先遍历\n");
    for (int i = 0; i < graph.vex_num; ++i)
        bfs_visited[i] = 0;
    InitQueue_Sq(&bfs_queue);
    for (int i = 0; i < graph.vex_num; ++i) {
        if (!bfs_visited[i])
            BFS(graph, i);
    }
}

void BFS(MGraph graph, int v) {
    visit(v, graph.vexs[v].content);
    bfs_visited[v] = 1;
    EnQueue_Sq(&bfs_queue, v);
    while (!QueueEmpty_Sq(bfs_queue)) {
        DeQueue_Sq(&bfs_queue, &v);
        for (int w = FirstNeighbor(graph, v); w >= 0; w = NextNeighbor(graph, v, w)) {
            if (!bfs_visited[w]) {
                visit(w, graph.vexs[w].content);
                bfs_visited[w] = 1;
                EnQueue_Sq(&bfs_queue, w);
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
    int visited[G.vex_num];
    for (int i = 0; i < G.vex_num; ++i) {
        d[i] = INFINITY;
        visited[i] = 0;
    }

    visited[u] = 1;
    d[u] = 0;
    SqQueue min_dis_queue;

    InitQueue_Sq(&min_dis_queue);

    EnQueue_Sq(&min_dis_queue, u);

    while (!QueueEmpty_Sq(min_dis_queue)) {
        DeQueue_Sq(&min_dis_queue, &u);
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {
            if (!visited[w]) {
                visited[w] = 1;
                d[w] = d[u] + 1;
                EnQueue_Sq(&min_dis_queue, w);
            }
        }
    }
    for (int i = 0; i < G.vex_num; ++i) {
        printf("%d->%d : %d\n", u, i, d[i]);
    }
}

/**
 * 深度优先遍历
 * @param G
 */
void DFSTraverse(MGraph G) {
    printf("深度优先遍历\n");
    for (int i = 0; i < G.vex_num; ++i)
        dfs_visited[i] = 0;
    for (int i = 0; i < G.vex_num; ++i) {
        if (!dfs_visited[i])
            DFS(G, i);
    }
}

void DFS(MGraph g, int v) {

    visit(v, g.vexs[v].content);

    dfs_visited[v] = 1;
    for (int w = FirstNeighbor(g, v); w >= 0; w = NextNeighbor(g, v, w)) {
        if (!dfs_visited[w])
            DFS(g, w);
    }

}

#endif //CLION_DATASTRUCTURE_GRAPH_TRAVEL_H
