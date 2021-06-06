//
// Created by han1254 on 6/6/21.
//
#include "CriticalPath.h"
int main() {
    ALGraph G;
    CreateDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/aoe/p_186_data.txt", &G);
    CriticalPath(G);
}