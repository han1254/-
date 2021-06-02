//
// Created by han1254 on 5/21/21.
// 十字链表法->有向图
//

#ifndef CLION_DATASTRUCTURE_OLGRAPH_H
#define CLION_DATASTRUCTURE_OLGRAPH_H
#include "../common.h"
#define MAX_VERTEX_NUM 20
typedef struct ArcBox {
    int tailvex, headvex;
    int val;
    struct ArcBox *hlink, *tlink;
    InfoType *info;
} ArcBox;
typedef struct VexNode{
    VertexType data;
    ArcBox *first_in, *first_out;
}VexNode;
typedef struct {
    GraphKind kind;
    VexNode xlist[MAX_VERTEX_NUM];//表头向量
    int vex_num, arc_num;
}OLGraph;
#endif //CLION_DATASTRUCTURE_OLGRAPH_H
