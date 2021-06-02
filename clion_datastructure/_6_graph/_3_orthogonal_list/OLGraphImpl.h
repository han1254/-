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

/**
 * tail ---> head
 * from       to
 * @param graph
 * @param from
 * @param to
 * @return
 */
int CreateDG_Arc(OLGraph* graph, int from, int to) {
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
int CreateDN_CreateArc(OLGraph* graph, int from, int to, int val) {
    ArcBox* arc = (ArcBox*)malloc(sizeof(ArcBox));
    arc->tailvex = from;
    arc->headvex = to;
    arc->val = val;
    arc->hlink = graph->xlist[to].first_in;
    arc->tlink = graph->xlist[from].first_out;
    graph->xlist[to].first_in = arc;
    graph->xlist[from].first_out = arc;
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
        CreateDN_CreateArc(graph, from, to, val);
    }
    fclose(fp);
    return 1;
}



#endif //CLION_DATASTRUCTURE_OLGRAPHIMPL_H
