//
// Created by han1254 on 5/20/21.
// 邻接表
//

#ifndef CLION_DATASTRUCTURE_ALGRAPHIMPL_H
#define CLION_DATASTRUCTURE_ALGRAPHIMPL_H

#include <bits/types/FILE.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

void printGraph(ALGraph graph) {
    for (int i = 0; i < graph.vex_num; ++i) {
        printf("(%d)%s->", graph.vertices[i].data.id, graph.vertices[i].data.content);
        ArcNode* node = graph.vertices[i].firstarc;
        while (node != NULL) {
            printf("%d->", node->adjvex);
            node = node->nextarc;
        }
        printf("Null\n");
    }
}

void printNet(ALGraph graph) {
    for (int i = 0; i < graph.vex_num; ++i) {
        printf("(%d)%s", graph.vertices[i].data.id, graph.vertices[i].data.content);
        ArcNode* node = graph.vertices[i].firstarc;
        while (node != NULL) {
            printf("-[cost:%d]->%d", node->val, node->adjvex);
            node = node->nextarc;
        }
        printf("->NULL\n");
    }
}

void printALGraph(ALGraph graph, GraphKind kind) {
    if (kind == DG || kind == UDG)
        printGraph(graph);
    else
        printNet(graph);
}


int FirstNeighbor(ALGraph g, int v) {
    ArcNode* arc = g.vertices[v].firstarc;
    if (arc == NULL) return -1;
    return arc->adjvex;
}

int NextNeighbor(ALGraph g, int v, int w) {
    ArcNode* arc = g.vertices[v].firstarc;
    while (arc != NULL && arc->adjvex != w) arc = arc->nextarc;
    if (arc == NULL || arc->nextarc == NULL) return -1;
    return arc->nextarc->adjvex;
}

int ReadBaseInfo(FILE* fpread, ALGraph* graph, int* vexNum, int* arcNum) {
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
    int count = 0;
    graph->vertices[count].data.content = (char*)malloc(sizeof(char) * 10);
    while(count < graph->vex_num && fgets(graph->vertices[count].data.content, 10, fpread) != NULL){
        graph->vertices[count].data.id = count;
        printf("%s", graph->vertices[count].data.content);
        count++;
        graph->vertices[count].data.content = (char*)malloc(sizeof(char) * 10);
    }
    return 1;
}

int CreateDG_CreateArc(ALGraph* graph, int from, int to, int* isFirst) {
    ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
    node->adjvex = to;
    node->nextarc = NULL;
    if (isFirst[from]) {//这个结点之前没被访问过，那就让他的firstarc = node
        graph->vertices[from].firstarc = node;
        isFirst[from] = 0;
    } else {//如果已经访问过该结点，则说明这个结点已经有firstrarc了
        ArcNode* firstArc = graph->vertices[from].firstarc;
        ArcNode* ptr = firstArc;
        while (ptr->nextarc != NULL) ptr = ptr->nextarc;
        ptr->nextarc = node;
    }
    return 1;
}


/**
 * 创建有向图
 * @param path 文件地址（绝对地址）
 * @param graph
 * @return
 */
int CreateDG(char* path, ALGraph* graph) {
    FILE* fpread;
    int vexNum;
    int arcNum;

    fpread = fopen(path, "r");
    if (fpread == NULL) {
        printf("file is error.");
        return -1;
    }
    ReadBaseInfo(fpread, graph, &vexNum, &arcNum);
    int isFirst[vexNum];
    for (int i = 0; i < vexNum; ++i)
        isFirst[i] = 1;//这个结点之前还没被访问过
    int from, to;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fpread, "%d %d", &from, &to);
        CreateDG_CreateArc(graph, from, to, isFirst);
    }
    fclose(fpread);
    return 1;
}
int CreateDN_CreateArc(ALGraph* graph, int from, int to, int val, int* isFirst) {
    ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
    node->adjvex = to;
    node->val = val;//这个是我加上的，用来存储网络的边权值
    node->nextarc = NULL;
    if (isFirst[from]) {
        graph->vertices[from].firstarc = node;
        isFirst[from] = 0;
    } else {
        ArcNode* firstArc = graph->vertices[from].firstarc;
        ArcNode* ptr = firstArc;
        while (ptr->nextarc != NULL) ptr = ptr->nextarc;
        ptr->nextarc = node;
    }
    return 1;
}
/**
 * 创建有向网
 * @param path
 * @param graph
 * @return
 */
int CreateDN(char* path, ALGraph* graph) {
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

/**
 * 建立无向图
 * @param path
 * @param graph
 * @return
 */
int CreateUDG(char* path, ALGraph* graph) {
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
        fscanf(fp, "%d %d", &from, &to);
        CreateDG_CreateArc(graph, from, to, isFirst);
        CreateDG_CreateArc(graph, to, from, isFirst);
    }
    fclose(fp);
    return 1;
}
/**
 * 建立无向网
 * @param path
 * @param graph
 * @return
 */
int CreateUDN(char* path, ALGraph* graph) {
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
        CreateDN_CreateArc(graph, to, from, val, isFirst);
    }
    return 1;
}

#endif //CLION_DATASTRUCTURE_ALGRAPHIMPL_H
