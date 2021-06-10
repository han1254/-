//
// Created by han1254 on 6/9/21.
//

#ifndef CLION_DATASTRUCTURE_SHORTESTPATH_DIJ_H
#define CLION_DATASTRUCTURE_SHORTESTPATH_DIJ_H
#include "../_1_adjacency_matrix/MGraphImpl.h"
#define FALSE 0
#define TRUE 1


void showPath(MGraph G, int v0, int matrix[G.vex_num][G.vex_num], int table[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i) {
        printf("起点：%s", G.vexs[v0].content);
        printf("终点：%s", G.vexs[i].content);
        printf("路径：\n");
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == TRUE) {
                printf("%s", G.vexs[j].content);
            }
        }
        printf("长度%d\n\n", table[i]);
    }
}

/**
 *
 * @param G
 * @param v0
 * @param P 若P[v][w]为TRUE，则w是从v0出发到v当前求得的最短路径上的顶点
 * @param D
 * final[v]为TRUE，当且仅当v∈S，即已经求得从v0到v的最短路径
 */
void ShortestPath_DIJ(MGraph G, int v0, int P[G.vex_num][G.vex_num],int D[]) {
    int final[G.vex_num];
    int v;
    for (v = 0; v < G.vex_num; ++v) {
        final[v] = FALSE;
        D[v] = G.arcs[v0][v].adj;
        for (int w = 0; w < G.vex_num; ++w)
            P[v][w] = FALSE;
        if (D[v] < INFINITY) {
            P[v][v0] = TRUE;
            P[v][v] = TRUE;
        }
    }

    D[v0] = 0;
    final[v0] = TRUE;
    for (int i = 1; i < G.vex_num; ++i) {
        int min = INFINITY;
        for (int w = 0; w < G.vex_num; ++w) {//找到次短路径
            if (!final[w]) {
                if (D[w] < min) {
                    v = w;
                    min = D[w];
                }
            }
        }
        final[v] = TRUE;
        for (int w = 0; w < G.vex_num; ++w) {//通过上面找到的次短路径，更新目前的值
            if (!final[w] && G.arcs[v][w].adj < INFINITY && (min + G.arcs[v][w].adj < D[w])) {//v0->v + v->w < v0->w，则更新P和D
                D[w] = min + G.arcs[v][w].adj;
                for (int j = 0; j < G.vex_num; ++j) {
                    P[w][j] = P[v][j];
                }
                P[w][w] = TRUE;
            }
        }
    }
}

#endif //CLION_DATASTRUCTURE_SHORTESTPATH_DIJ_H
