//
// Created by han1254 on 5/14/21.
// 定义邻接矩阵
//

#ifndef CLION_DATASTRUCTURE_MGRAPH_H
#define CLION_DATASTRUCTURE_MGRAPH_H
#include "../../common_status.h"
#include "../common.h"
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 100
//typedef struct VexType {
//    int id;
//    char* content;
//    int inDegree;//in degree
//    int outDegree;//out degree
//    int degree;
//}VexType;
//typedef enum {DG, DN, UDG, UDN} GraphKind;//有向图，有向网，无向图，无向网
typedef struct ArcCell{//定义“边”结构体
    int adj;
    char* info;
}ArcCell, **AdjMatrix;
typedef struct {
    GraphKind kind;
    int vex_num, arc_num;
    VertexType* vexs;//每个结点的内容
    AdjMatrix arcs;//判断结点之间的连接情况
} MGraph;


int FirstNeighbor(MGraph graph, int x) {
    for (int i = 0; i < graph.vex_num; ++i) {
        if (graph.arcs[x][i].adj == 1) return i;
    }
    return -1;
}


int NextNeighbor(MGraph graph, int x, int y) {
    for (int i = y + 1; i < graph.vex_num; ++i) {
        if (graph.arcs[x][i].adj == 1) return i;
    }
    return -1;
}

#endif //CLION_DATASTRUCTURE_MGRAPH_H
