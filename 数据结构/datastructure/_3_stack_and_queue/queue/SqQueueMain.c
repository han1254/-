#include "SqQueueImpl.h"

int main() {
    SqQueue queue;
    InitQueue_Sq(&queue);

    EnQueue_Sq(&queue, 8);
    EnQueue_Sq(&queue, 9);
    EnQueue_Sq(&queue, 4);
    EnQueue_Sq(&queue, 1);

    int t;
    while (!QueueEmpty_Sq(queue)) {
        DeQueue_Sq(&queue, &t);
        printf("%d ", t);
    }
    printf("\n");
}