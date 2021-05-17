//
// Created by han1254 on 5/14/21.
//

#ifndef CLION_DATASTRUCTURE_MGRAPHIMPL_H
#define CLION_DATASTRUCTURE_MGRAPHIMPL_H

#include <stdlib.h>
#include "MGraph.h"
#include "stdio.h"

int ReadBaseInfo(FILE* fpread, MGraph* graph, int* vexNum, int* arcNum) {
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
    graph->vexs = (char**)malloc(sizeof(char*) * graph->vex_num);
    for (int i = 0; i < graph->vex_num; ++i)
        graph->vexs[i] = (char*)malloc(sizeof(char) * 10);
    int count = 0;
    while(count < graph->vex_num && fgets(graph->vexs[count], 10, fpread) != NULL){
        printf("%s", graph->vexs[count]);
        count++;
    }
    graph->arcs = (ArcCell**)malloc(sizeof(ArcCell*) * graph->vex_num);
    for (int i = 0; i < graph->vex_num; ++i)
        graph->arcs[i] = (ArcCell*)malloc(sizeof(ArcCell) * graph->vex_num);
    return 1;
}
/**
 * 创建有向图
 * @param path 文件地址（绝对地址）
 * @param graph
 * @return
 */
int CreateDG(char* path, MGraph* graph) {
    FILE* fpread;
    int vexNum;
    int arcNum;
    int realArcNum = 0;
    fpread = fopen(path, "r");
    if (fpread == NULL) {
        printf("file is error.");
        return -1;
    }
//    fscanf(fpread, "%d\n", &graph->kind);//读入图的类型
//    printf("type:%d\n", graph->kind);
//    fscanf(fpread, "%d %d\n", &graph->vex_num, &graph->arc_num);//
//    printf("vexNum: %d, arcNum: %d\n", graph->vex_num, graph->arc_num);
//    vexNum = graph->vex_num;
//    graph->vexs = (char**)malloc(sizeof(char*) * vexNum);
//    for (int i = 0; i < vexNum; ++i)
//        graph->vexs[i] = (char*)malloc(sizeof(char) * 10);
//    int count = 0;
//    while(count < vexNum && fgets(graph->vexs[count], 10, fpread) != NULL){
//        printf("%s", graph->vexs[count]);
//        count++;
//    }
    ReadBaseInfo(fpread, graph, &vexNum, &arcNum);
//    graph->arcs = (ArcCell**)malloc(sizeof(ArcCell*) * vexNum);
//    for (int i = 0; i < vexNum; ++i)
//        graph->arcs[i] = (ArcCell*)malloc(sizeof(ArcCell) * vexNum);
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            fscanf(fpread, "%d", &graph->arcs[i][j].adj);
            if (graph->arcs[i][j].adj == 1) realArcNum++;
        }
    }
    if (realArcNum != graph->arc_num) {
        printf("输入边的个数与文件中实际个数不一致！\n");
        return 0;
    }
    fclose(fpread);
    return 1;
}

int CreateDN(char* path, MGraph* graph) {
    FILE *fp;
    int vexNum = 0;
    int arcNum = 0;
    fp = fopen(path, "r");
    ReadBaseInfo(fp, graph, &vexNum, &arcNum);
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            graph->arcs[i][j].adj = INFINITY;
        }
    }
    int tempIndexI, tempIndexJ;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fp, "%d", &tempIndexI);
        fscanf(fp, "%d", &tempIndexJ);
        printf("%d %d:", tempIndexI, tempIndexJ);
        fscanf(fp, "%d", &graph->arcs[tempIndexI][tempIndexJ].adj);
        printf("%d\n", graph->arcs[tempIndexI][tempIndexJ].adj);
    }
    return 1;
}

#endif //CLION_DATASTRUCTURE_MGRAPHIMPL_H
