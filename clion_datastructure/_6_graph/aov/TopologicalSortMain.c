//
// Created by han1254 on 6/5/21.
//

#include "TopologicalSortHeader.h"

int main() {
    ALGraph graph;
    //课本181页的课程数据
    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/aov/p_181_data.txt", &graph);
    printf("正序排列：\n");
    TopologicalSort(graph);
    printf("逆序排列：\n");
    DFS_Reverse_Topological_Sort(graph);
}