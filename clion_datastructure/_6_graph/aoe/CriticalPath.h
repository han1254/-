//
// Created by han1254 on 6/6/21.
//

#ifndef CLION_DATASTRUCTURE_CRITICALPATH_H
#define CLION_DATASTRUCTURE_CRITICALPATH_H
#include "../_2_adjacency_list/ALGraphImpl.h"
#include "../../_3_stack_and_queue/stack/SqStackImpl.h"
#define ERROR 0
#define OK 1;

void FindInDegree(ALGraph g, int *degree);
int TopologicalOrder(ALGraph G, SqStack* T, int* ve);
int CriticalPath(ALGraph G);

void printCriticalPath(int from, int to, int flag, int dut, int ee, int el) {
    if (flag) printf("*");
    printf("%d->%d, 最早开始时间：%d, 最晚开始时间：%d，活动持续时间：%d\n", from, to, ee, el, dut);
}
int CriticalPath(ALGraph G) {
    SqStack T;
    int ee;
    int el;
    int tag;
    int ve[G.vex_num];
    int vl[G.vex_num];
    int j;
    if (!TopologicalOrder(G, &T, ve)) return ERROR;
    for (int i = 0; i < G.vex_num; ++i)
        vl[i] = ve[G.vex_num - 1];
    while (!StackEmpty(T)) {
        Pop(&T, &j);
        for(ArcNode* p = G.vertices[j].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            int dut = p->val;
            if (vl[k] - dut < vl[j])
                vl[j] = vl[k] - dut;
        }
    }

    for (int i = 0; i < G.vex_num; ++i) {
        for (ArcNode* p = G.vertices[i].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            int dut = p->val;
            ee = ve[i];
            el = vl[k] - dut;
            tag = ee == el ? 1 : 0;
            printCriticalPath(i, k, tag, dut, ee, el);
        }
    }
    return OK;
}

int TopologicalOrder(ALGraph G, SqStack* T, int* ve) {
    // 有向网G采用邻接表存储结构，求各个顶点事件的最早发生时间ve
    // T为拓扑序列顶点栈，S为零入度顶点栈
    // 若G无回路，则使用T返回G的一个拓扑序列，并且函数值为OK（1），否则为ERROR（0）
    int indegree[G.vex_num];
    FindInDegree(G, indegree);
    InitStack(T);
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < G.vex_num; ++i) //创建零入度节点栈
        if (indegree[i] == 0) Push(&S, i);
    int count = 0;
    int mark;
    for (int i = 0; i < G.vex_num; ++i)
        ve[i] = 0;
    while (!StackEmpty(S)) {
        Pop(&S, &mark);
        Push(T, mark);
        if (mark == 2) printf("test\n");
        count++;
        for (ArcNode* p = G.vertices[mark].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            if (--indegree[k] == 0) Push(&S, k);
            if (ve[mark] + p->val > ve[k])//这里，我的数据结构跟书上有略微不同，我是用的val来表示边上的值
                ve[k] = ve[mark] + p->val;
        }
    }
    if (count < G.vex_num) return ERROR;
    return OK;
}

/**
 * 记录每个结点的入度
 * @param g
 * @param degree
 */
void FindInDegree(ALGraph g, int *degree) {
    for (int i = 0; i < g.vex_num; ++i)
        degree[i] = 0;
    for (int i = 0; i < g.vex_num; ++i) {
        ArcNode* node = g.vertices[i].firstarc;
        while (node != NULL) {
            degree[node->adjvex]++;
            node = node->nextarc;
        }
    }
}

#endif //CLION_DATASTRUCTURE_CRITICALPATH_H
