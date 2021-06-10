//
// Created by han1254 on 6/9/21.
//

#include "ShortestPath_DIJ.h"

#include "ShortestPath_FLOYD.h"
int main() {
    char* t = "/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/shortest_path/p_188_data.txt";
    MGraph G;
    CreateDN(t, &G);
    int table[G.vex_num];
    int matrix[G.vex_num][G.vex_num];
    ShortestPath_DIJ(G, 0, matrix, table);
    showPath(G, 0, matrix, table, G.vex_num);

    int D[G.vex_num][G.vex_num];
    int P[G.vex_num][G.vex_num][G.vex_num];

    ShortestPath_FLOYD(G, P, D);

    showFLOYDPath(G, P, D);
}