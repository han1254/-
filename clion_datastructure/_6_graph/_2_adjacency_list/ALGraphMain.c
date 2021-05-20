//
// Created by han1254 on 5/20/21.
//

#include "ALGraphImpl.h"

int main() {
    ALGraph DG;

    CreateDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DG.txt", &DG);

    printALGraph(DG, 0);

    ALGraph DN;

    CreateDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/DN.txt", &DN);

    printALGraph(DN, 1);

    ALGraph UDG;

    CreateUDG("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDG.txt", &UDG);

    printALGraph(UDG, 2);

    ALGraph UDN;

    CreateUDN("/home/han1254/Documents/PGEE/clion_datastructure/_6_graph/data/UDN.txt", &UDN);

    printALGraph(UDN, 3);
}