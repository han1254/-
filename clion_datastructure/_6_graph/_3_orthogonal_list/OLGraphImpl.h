//
// Created by han1254 on 5/21/21.
//

#ifndef CLION_DATASTRUCTURE_OLGRAPHIMPL_H
#define CLION_DATASTRUCTURE_OLGRAPHIMPL_H

#include <bits/types/FILE.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "OLGraph.h"
//void printGraph(OLGraph graph) {
//    for (int i = 0; i < graph.vex_num; ++i) {
//        printf("(%d)%s->", graph.vertices[i].data.id, graph.vertices[i].data.content);
//        ArcNode* node = graph.vertices[i].firstarc;
//        while (node != NULL) {
//            printf("%d->", node->adjvex);
//            node = node->nextarc;
//        }
//        printf("Null\n");
//    }
//}
//
//void printNet(ALGraph graph) {
//    for (int i = 0; i < graph.vex_num; ++i) {
//        printf("(%d)%s", graph.vertices[i].data.id, graph.vertices[i].data.content);
//        ArcNode* node = graph.vertices[i].firstarc;
//        while (node != NULL) {
//            printf("-[cost:%d]->%d", node->val, node->adjvex);
//            node = node->nextarc;
//        }
//        printf("->NULL\n");
//    }
//}
//
//void printALGraph(ALGraph graph, GraphKind kind) {
//    if (kind == DG || kind == UDG)
//        printGraph(graph);
//    else
//        printNet(graph);
//}

int ReadBaseInfo(FILE* fpread, OLGraph* graph, int* vexNum, int* arcNum) {
    if (fpread == NULL) {
        printf("file is error.");
        return 0;
    }
    fscanf(fpread, "%d\n", &graph->kind);//读入图的类型
    printf("type:%d\n", graph->kind);
    fscanf(fpread, "%d %d\n", &graph->vex_num, &graph->arc_num);//
    printf("vexNum: %d, arcNum: %d\n", graph->vex_num, graph->arc_num);
    *vexNum = graph->vex_num;
    *arcNum = graph->arc_num;
    int index = 0;
    VertexType vexData = graph->xlist[index].data;
    vexData.content = (char*)malloc(sizeof(char) * 10);
    while(index < graph->vex_num && fgets(vexData.content, 10, fpread) != NULL){
        vexData.id = index;
        printf("%s", vexData.content);
        graph->xlist[index].first_in = NULL;
        graph->xlist[index].first_out = NULL;
        index++;
        vexData = graph->xlist[index].data;
        vexData.content = (char*)malloc(sizeof(char) * 10);
    }
    return 1;
}

int CreateDG_Arc(OLGraph* graph, int from, int to) {
//    OLGraph * node = (OLGraph *)malloc(sizeof(OLGraph));
//    node-> = to;
//    node->nextarc = NULL;
//    if (isFirst[from]) {
//        graph->vertices[from].firstarc = node;
//        isFirst[from] = 0;
//    } else {
//        ArcNode* firstArc = graph->vertices[from].firstarc;
//        ArcNode* ptr = firstArc;
//        while (ptr->nextarc != NULL) ptr = ptr->nextarc;
//        ptr->nextarc = node;
//    }
    ArcBox* arc = (ArcBox*)malloc(sizeof(ArcBox));
    arc->tailvex = from;
    arc->headvex = to;
    arc->hlink = graph->xlist[to].first_in;
    arc->tlink = graph->xlist[from].first_out;
    graph->xlist[to].first_in = arc;
    graph->xlist[from].first_out = arc;
    return 1;
}


/**
 * 创建有向图
 * @param path 文件地址（绝对地址）
 * @param graph
 * @return
 */
int CreateDG(char* path, OLGraph* graph) {
    FILE* fpread;
    int vexNum;
    int arcNum;

    fpread = fopen(path, "r");
    if (fpread == NULL) {
        printf("file is error.");
        return -1;
    }
    ReadBaseInfo(fpread, graph, &vexNum, &arcNum);
    int from, to;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fpread, "%d %d", &from, &to);

        CreateDG_Arc(graph, from, to);
    }
    fclose(fpread);
    return 1;
}
int CreateDN_CreateArc(OLGraph* graph, int from, int to, int val, int* isFirst) {
//    ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
//    node->adjvex = to;
//    node->val = val;//这个是我加上的，用来存储网络的边权值
//    node->nextarc = NULL;
//    if (isFirst[from]) {
//        graph->vertices[from].firstarc = node;
//        isFirst[from] = 0;
//    } else {
//        ArcNode* firstArc = graph->vertices[from].firstarc;
//        ArcNode* ptr = firstArc;
//        while (ptr->nextarc != NULL) ptr = ptr->nextarc;
//        ptr->nextarc = node;
//    }
    return 1;
}
/**
 * 创建有向网
 * @param path
 * @param graph
 * @return
 */
int CreateDN(char* path, OLGraph* graph) {
    FILE *fp;
    int vexNum = 0;
    int arcNum = 0;
    fp = fopen(path, "r");
    ReadBaseInfo(fp, graph, &vexNum, &arcNum);
    int isFirst[vexNum];
    for (int i = 0; i < vexNum; ++i)
        isFirst[i] = 1;
    int from, to;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fp, "%d", &from);
        fscanf(fp, "%d", &to);
        printf("%d %d:", from, to);
        int val;
        fscanf(fp, "%d", &val);
        printf("%d\n", val);
        CreateDN_CreateArc(graph, from, to, val, isFirst);
    }
    fclose(fp);
    return 1;
}



#endif //CLION_DATASTRUCTURE_OLGRAPHIMPL_H
