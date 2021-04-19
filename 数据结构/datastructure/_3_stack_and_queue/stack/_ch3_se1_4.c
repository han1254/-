#include <stdlib.h>
#include "stdio.h"

typedef struct LNode {
    struct LNode* next;
    char data;
}LNode, *LinkList;

LinkList createNode(char c) {
    LinkList l = (LinkList)malloc(sizeof(LNode));
    l->data = c;
    return l;
}

int gc(LinkList l, int n) {
    int i;
    char s[n / 2];
    LinkList node = l->next;
    for(i = 0; i < n / 2; i++) {
        s[i] = node->data;
        node = node->next;
    }
    i--;
    if(n / 2 == 1) node = node->next;
    while(i >= 0 && node != NULL) {
        if(s[i] != node->data) return 0;
        i--;
        node = node->next;
    }
    if(i >= 0) return 0;
    return 1;
}

int judgeGc() {
    LinkList head = (LinkList)malloc(sizeof(LNode));
    LinkList node = head;
    int n;
    printf("please enter n:");
    scanf("%d", &n);
    getchar();
    char ch;
    for (int i = 0; i < n; ++i) {
        ch = (char)getchar();
        getchar();
        node->next = createNode(ch);
        node = node->next;
    }
    return gc(head, n);
}

int main() {
	printf("%d\n", judgeGc());
}

