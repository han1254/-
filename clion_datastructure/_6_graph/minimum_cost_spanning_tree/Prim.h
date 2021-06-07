//
// Created by han1254 on 6/7/21.
// Prim算法
//

#ifndef CLION_DATASTRUCTURE_PRIM_H
#define CLION_DATASTRUCTURE_PRIM_H
#include "../_1_adjacency_matrix/MGraphImpl.h"

typedef struct {
    int adjvex;
    int lowcost;
}CloseEdgeNode, CloseEdges[MAX_VERTEX_NUM];

int minimum(const CloseEdges a, int n) {
    int i = 0;
    int k = -1;
    int min = INFINITY;
    for (; i < n; ++i) {
        if (a[i].lowcost > 0 && a[i].lowcost <= min) {//lowcost大于0说明其在V - U集合里
            k = i;
            min = a[i].lowcost;
        }
    }
    if (k == -1) printf("error!\n");
    printf("%d--%d, cost:%d\n", k, a[k].adjvex, a[k].lowcost);
    return k;
}

void MiniSpanTree_PRIM(MGraph G, int u) {
    CloseEdges closeedge;
    int k = LocateVex(G, u);
    for (int i = 0; i < G.vex_num; ++i) {
        if (i != k) {
            CloseEdgeNode node;
            node.adjvex = u;
            node.lowcost = G.arcs[k][i].adj;
            closeedge[i] = node;
        }
    }

    closeedge[k].lowcost = 0;//u进入，U={u}
    for (int i = 1; i < G.vex_num; ++i) {
        k = minimum(closeedge, G.vex_num);
//        printf("%d进入U集合\n", k);
        closeedge[k].lowcost = 0;//找到V-U集合中到U集合最小的顶点，加入U集合
        for (int j = 0; j < G.vex_num; ++j) {
            if (G.arcs[k][j].adj < closeedge[j].lowcost) {//通过刚刚找到的k顶点，更新U到V-U中路径
                CloseEdgeNode node;
                node.lowcost = G.arcs[k][j].adj;
                node.adjvex = k;
                closeedge[j] = node;
            }
        }
    }
}
#endif //CLION_DATASTRUCTURE_PRIM_H
