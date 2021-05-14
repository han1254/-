//
// Created by han1254 on 5/14/21.
// 定义邻接矩阵
//

#ifndef CLION_DATASTRUCTURE_MGRAPH_H
#define CLION_DATASTRUCTURE_MGRAPH_H
#include "../common_status.h"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 100
typedef enum {DG, DN, UDG, UDN} GraphKind;//有向图，有向网，无向图，无向网
typedef struct ArcCell{//定义“边”结构体
    int adj;
    char* info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    char* vexs[MAX_VERTEX_NUM];//每个结点的内容
    AdjMatrix arcs;//判断结点之间的连接情况
    int vex_num, arc_num;
    GraphKind kind;
} MGraphKind;



#endif //CLION_DATASTRUCTURE_MGRAPH_H
