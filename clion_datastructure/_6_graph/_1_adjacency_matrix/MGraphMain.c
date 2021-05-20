//
// Created by han1254 on 5/14/21.
//




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MGraphImpl.h"
int main()
{

    MGraph DG;
    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DG.txt", &DG);

    for (int i = 0; i < DG.vex_num; ++i) {
        for (int j = 0; j < DG.vex_num; ++j) {
            printf("%d ", DG.arcs[i][j].adj);
        }
        printf("\n");
    }


    MGraph DN;
    CreateDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DN.txt", &DN);
    for (int i = 0; i < DN.vex_num; ++i) {
        for (int j = 0; j < DN.vex_num; ++j) {
            if (DN.arcs[i][j].adj < INFINITY)
                printf("%d ", DN.arcs[i][j].adj);
            else
                printf("%s", "∞ ");
        }
        printf("\n");
    }

    MGraph UDG;
    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDG.txt", &UDG);
    for (int i = 0; i < UDG.vex_num; ++i) {
        for (int j = 0; j < UDG.vex_num; ++j) {
            printf("%d ", UDG.arcs[i][j].adj);
        }
        printf("\n");
    }
    MGraph UDN;
    CreateUDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDN.txt", &UDN);
    for (int i = 0; i < UDN.vex_num; ++i) {
        for (int j = 0; j < UDN.vex_num; ++j) {
            if (UDN.arcs[i][j].adj < INFINITY)
                printf("%d  ", UDN.arcs[i][j].adj);
            else
                printf("%s", "∞  ");
        }
        printf("\n");
    }
    return 0;
}
