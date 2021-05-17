//
// Created by han1254 on 5/14/21.
//




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MGraphImpl.h"
int main()
{
//    char buf[80];
//    getcwd(buf,sizeof(buf));
//    printf("current working directory: %s\n", buf);
//    int a[4][4];
//    FILE* fpread;
//    int temp;
//    int type;
//    int m, n;
//    char* temps = (char*)malloc(sizeof(char));
//    fpread = fopen("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/data.txt", "r");
//    if (fpread == NULL)
//    {
//        printf("file is error.");
//        return -1;
//    }
//    fscanf(fpread, "%d\n", &type);
//    printf("type:%d\n", type);
//    fscanf(fpread, "%d %d\n", &m, &n);
//    printf("m: %d, n: %d\n", m, n);
//    int count = 0;
//    while(count < m && fgets(temps, m, fpread) != NULL){
//        printf("%s", temps);
//        count++;
//    }
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            fscanf(fpread, "%d", &temp);
//
//            printf("%d\n", temp);
//        }
//    }
//    fclose(fpread);

    MGraph graph;
    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DG.txt", &graph);

    for (int i = 0; i < graph.vex_num; ++i) {
        for (int j = 0; j < graph.vex_num; ++j) {
            printf("%d ", graph.arcs[i][j].adj);
        }
        printf("\n");
    }


    MGraph DNGraph;
    CreateDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DN.txt", &DNGraph);
    for (int i = 0; i < DNGraph.vex_num; ++i) {
        for (int j = 0; j < DNGraph.vex_num; ++j) {
            if (DNGraph.arcs[i][j].adj < INFINITY)
                printf("%d ", DNGraph.arcs[i][j].adj);
            else
                printf("%s", "∞ ");
        }
        printf("\n");
    }
    return 0;
}
