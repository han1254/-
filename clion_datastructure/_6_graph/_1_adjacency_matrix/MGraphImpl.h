//
// Created by han1254 on 5/14/21.
//

#ifndef CLION_DATASTRUCTURE_MGRAPHIMPL_H
#define CLION_DATASTRUCTURE_MGRAPHIMPL_H

#include <stdlib.h>
#include "MGraph.h"
#include "stdio.h"

void showUDG(MGraph graph) {
    for (int i = 0; i < graph.vex_num; ++i) {
        for (int j = 0; j < graph.vex_num; ++j) {
            printf("%d ", graph.arcs[i][j].adj);
        }
        printf("\n");
    }
}

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
    graph->vexs = (VertexType *)malloc(sizeof(VertexType) * graph->vex_num);
    for (int i = 0; i < graph->vex_num; ++i) {
        graph->vexs[i].content = (char*)malloc(sizeof(char) * 10);
        graph->vexs[i].id = i;
    }

    int count = 0;
    while(count < graph->vex_num && fgets(graph->vexs[count].content, 10, fpread) != NULL){
        printf("%s", graph->vexs[count].content);
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
    fpread = fopen(path, "r");
    if (fpread == NULL) {
        printf("file is error.");
        return -1;
    }
    ReadBaseInfo(fpread, graph, &vexNum, &arcNum);
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            graph->arcs[i][j].adj = 0;
        }
    }
    int row, col;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fpread, "%d %d", &row, &col);
        graph->arcs[row][col].adj = 1;
    }
    fclose(fpread);
    return 1;
}

/**
 * 创建有向网
 * @param path
 * @param graph
 * @return
 */
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
    fclose(fp);
    return 1;
}

/**
 * 建立无向图
 * @param path
 * @param graph
 * @return
 */
int CreateUDG(char* path, MGraph* graph) {
    FILE *fp;
    int vexNum = 0;
    int arcNum = 0;
    fp = fopen(path, "r");
    ReadBaseInfo(fp, graph, &vexNum, &arcNum);
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            graph->arcs[i][j].adj = 0;
        }
    }
    int row, col;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fp, "%d", &row);
        fscanf(fp, "%d", &col);
        graph->arcs[row][col].adj = 1;
        graph->arcs[col][row].adj = 1;
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
int CreateUDN(char* path, MGraph* graph) {
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
    int row, col, val;
    for (int i = 0; i < arcNum; ++i) {
        fscanf(fp, "%d", &row);
        fscanf(fp, "%d", &col);
        fscanf(fp, "%d", &val);
        graph->arcs[row][col].adj = val;
        graph->arcs[col][row].adj = val;
    }
    return 1;
}

int LocateVex(MGraph G, int v) {
    return v;
}


#endif //CLION_DATASTRUCTURE_MGRAPHIMPL_H
