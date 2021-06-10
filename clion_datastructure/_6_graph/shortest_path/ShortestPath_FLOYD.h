//
// Created by han1254 on 6/10/21.
//

#ifndef CLION_DATASTRUCTURE_SHORTESTPATH_FLOYD_H
#define CLION_DATASTRUCTURE_SHORTESTPATH_FLOYD_H

#include <memory.h>
#include "../_1_adjacency_matrix/MGraphImpl.h"
#include "../../util/str_cut.h"
#define FALSE 0
#define TRUE 1

void showFLOYDPath(MGraph G, int P[][G.vex_num][G.vex_num], int D[][G.vex_num]) {
    for (int i = 0; i < G.vex_num; ++i) {
        for (int j = 0; j < G.vex_num; ++j) {
            //由于作者失误，当初在读入每个结点的名字的时候把回车也给读进去了，所以如今只能如此繁琐地去掉最后一个回车
//            char* s1 = G.vexs[i].content;
//            int len1 = (int)strlen(s1);
//            char rs1[len1 - 1];
//            str_copy(s1, len1 - 1, rs1);
//            char* s2 = G.vexs[j].content;
//            int len2 = (int)strlen(s2);
//            char rs2[len2 - 1];
//            str_copy(s2, len2 - 1, rs2);

            char* s1 = G.vexs[i].content;
            int len1 = (int)strlen(s1);
            s1[len1] = '\0';
            char* s2 = G.vexs[j].content;
            int len2 = (int)strlen(s2);
            s2[len2] = '\0';
            printf("%s↓\n%s:", s1, s2);

            for (int k = 0; k < G.vex_num; ++k) {
                if (P[i][j][k] == TRUE) {
                    printf("%s", G.vexs[k].content);
                }
            }
            printf("\n");
        }
    }
}

void ShortestPath_FLOYD(MGraph G, int P[][G.vex_num][G.vex_num], int D[][G.vex_num]) {
    for (int v = 0; v < G.vex_num; ++v) {
        for (int w = 0; w < G.vex_num; ++w) {
            D[v][w] = G.arcs[v][w].adj;
            for (int u = 0; u < G.vex_num; ++u) P[v][w][u] = FALSE;
            if (D[v][w] < INFINITY) {
                P[v][w][v] = TRUE;
                P[v][w][w] = TRUE;
            }
        }
    }

    for (int u = 0; u < G.vex_num; ++u) {
        for (int v = 0; v < G.vex_num; ++v) {
            for (int w = 0; w < G.vex_num; ++w) {
                if ((D[v][u] < INFINITY && D[u][w] < INFINITY)
                && (D[v][u] + D[u][w] < D[v][w])) {
                    D[v][w] = D[v][u] + D[u][w];
                    for (int i = 0; i < G.vex_num; ++i)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];//将v到u上的点和u到w上的点合并到v到w路径上
                }
            }
        }
    }
}

#endif //CLION_DATASTRUCTURE_SHORTESTPATH_FLOYD_H
