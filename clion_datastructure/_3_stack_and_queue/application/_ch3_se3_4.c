//
// Created by han1254 on 4/25/21.
//

#include <stdlib.h>
#include "common_header.h"
Queue ferryQueue;
Queue truckQueue;//货车t
Queue cacheQueue;//客车c
void manage() {

    int i = 0, j = 0;
    while (j < 10) {
        char t;
        if (i < 4) {
            if (!QueueEmpty(cacheQueue)) {//客车队列不空
                DeQueue(&cacheQueue, &t);
                EnQueue(&ferryQueue, t);
                i++;
                j++;
            } else {//客车队列为空，货车填补
                if (!QueueEmpty(truckQueue)) {//货车队列不空
                    DeQueue(&truckQueue, &t);
                    EnQueue(&ferryQueue, t);
                    i++;
                    j++;
                } else {//两个队列都为空
                    break;
                }
            }
        } else {
            if (!QueueEmpty(truckQueue)) {
                DeQueue(&truckQueue, &t);
                EnQueue(&ferryQueue, t);
                i = 0;
                j++;
            } else {
                if (!QueueEmpty(cacheQueue)) {
                    DeQueue(&cacheQueue, &t);
                    EnQueue(&ferryQueue, t);
                    i = 1;
                    j++;
                } else {
                    break;
                }
            }
        }
    }


}

int main() {
    InitQueue(&ferryQueue);
    InitQueue(&truckQueue);
    InitQueue(&cacheQueue);

    char* truck = (char*)malloc(sizeof(char));
    char* cache = (char*)malloc(sizeof(char));
    printf("输入货车序列：\n");
    scanf("%s", truck);
    printf("输入客车序列：\n");
    scanf("%s", cache);
    int i = 0;
    while (truck[i] != '\0') {
        EnQueue(&truckQueue, truck[i++]);
    }
    i = 0;
    while (cache[i] != '\0') {
        EnQueue(&cacheQueue, cache[i++]);
    }

    PrintQueue(truckQueue);
    PrintQueue(cacheQueue);

    manage();

    PrintQueue(ferryQueue);
}
