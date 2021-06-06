//
// Created by han1254 on 6/5/21.
// 拓扑排序
//

#ifndef CLION_DATASTRUCTURE_TOPOGICALSORTHEADER_H
#define CLION_DATASTRUCTURE_TOPOGICALSORTHEADER_H
#include "../_2_adjacency_list/ALGraphImpl.h"
#include "../../_3_stack_and_queue/stack/SqStackImpl.h"
int* indegree;
int* indegree_dfs;
void FindInDegree(ALGraph g, int *a);

void DFS(ALGraph graph, int v, int* visited) {
    ArcNode* arc = graph.vertices[v].firstarc;
    visited[v] = 1;
    while (arc != NULL) {
        if (!visited[arc->adjvex]) {
            DFS(graph, arc->adjvex, visited);
        }
        arc = arc->nextarc;
    }
    printf("%d, %s", v, graph.vertices[v].data.content);
}

/**
 * 利用DFS逆序输出拓扑排序
 * @param G
 */
void DFS_Reverse_Topological_Sort(ALGraph G) {
    int* visited = (int*) malloc(sizeof(int) * G.vex_num);
    for (int i = 0; i < G.vex_num; ++i)
        visited[i] = 0;
    indegree_dfs = (int*)malloc(sizeof(int) * G.vex_num);
    FindInDegree(G, indegree_dfs);
    int first_zero_degree = -1;
    for (int i = 0; i < G.vex_num; ++i) {
        if (indegree_dfs[i] == 0) {
            first_zero_degree = i;
            DFS(G, first_zero_degree, visited);
        }

    }
    if (first_zero_degree == -1) {
        printf("error\n");
        return;
    }

}


/**
 * 拓扑排序
 * @param G
 * @return
 */
int TopologicalSort(ALGraph G) {
    indegree = (int*)malloc(sizeof(int) * G.vex_num);
    FindInDegree(G, indegree);
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < G.vex_num; ++i)
        if (!indegree[i]) Push(&S, i);//入度为0者入栈
    int count = 0;//对输出顶点计数
    int out;
    while (!StackEmpty(S)) {
        Pop(&S, &out);
        printf("%d, %s", out, G.vertices[out].data.content);
        count++;
        for (ArcNode* p = G.vertices[out].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            if (!--indegree[k]) Push(&S, k);
        }
    }

    if (count < G.vex_num) return 0;
    return 1;
}

/**
 * 记录每个结点的入度
 * @param g
 * @param degree
 */
void FindInDegree(ALGraph g, int *degree) {
    for (int i = 0; i < g.vex_num; ++i)
        degree[i] = 0;
    for (int i = 0; i < g.vex_num; ++i) {
        ArcNode* node = g.vertices[i].firstarc;
        while (node != NULL) {
            degree[node->adjvex]++;
            node = node->nextarc;
        }
    }
}

#endif //CLION_DATASTRUCTURE_TOPOGICALSORTHEADER_H
