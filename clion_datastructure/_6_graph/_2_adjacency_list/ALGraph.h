//
// Created by han1254 on 5/20/21.
// 邻接表
//

#ifndef CLION_DATASTRUCTURE_ALGRAPH_H
#define CLION_DATASTRUCTURE_ALGRAPH_H
#define MAX_VERTEX_NUM 100
#include "../common.h"
//typedef enum {DG, DN, UDG, UDN} GraphKind;//有向图，有向网，无向图，无向网
//
//typedef struct InfoType {
//    char* msg;
//} InfoType;
//typedef struct VertexType {
//    int id;//结点的位置
//    int adj;//如果你想为每个点设置一个值，可以设置给这个变量
//    int inDegree;//入度
//    int outDegree;//出度
//    int degree;//度
//    char* content;//比如你想给结点起一个名字
//    InfoType *info;//其他信息，可以自定义拓展InfoType结构体
//} VertexType;

typedef struct ArcNode {
    int adjvex;
    int val;
    struct ArcNode* nextarc;
    InfoType *info;
}ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode* firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vex_num, arc_num;
    GraphKind kind;
}ALGraph;

#endif //CLION_DATASTRUCTURE_ALGRAPH_H
