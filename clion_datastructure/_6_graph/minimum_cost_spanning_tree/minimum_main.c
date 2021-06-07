//
// Created by han1254 on 6/7/21.
//
#include "Prim.h"
#include "Kruskal.h"
int main() {
    //课本p174的无向网
    char* path = "/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/minimum_cost_spanning_tree/udn_data.txt";
    MGraph G;
    CreateUDN(path, &G);
    MiniSpanTree_PRIM(G, 0);
}