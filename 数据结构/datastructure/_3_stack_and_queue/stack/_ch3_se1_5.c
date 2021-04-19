#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define OP_LEFT 0
#define OP_RIGHT 1
typedef struct {
    int data[MAX_SIZE];
    int top_left;
    int top_right;
} SharedStack;

int push(int i, SharedStack* sst, int data) {
    if(sst->top_right - sst->top_left == 1) {
        printf("栈满，无法添加!\n");
        return 0;
    }
    if(i == OP_LEFT)
        sst->data[++sst->top_left] = data;
    else
        sst->data[--sst->top_right] = data;
    return 1;
}

int pop(int i, SharedStack* sst, int* e) {
    if(i == OP_LEFT) {
        if(sst->top_left == -1) {
            printf("左栈空，无法弹出!\n");
            return 0;
        }
        *e = sst->data[sst->top_left--];
    } else {

        if(sst->top_right == MAX_SIZE) {
            printf("右栈空，无法弹出！\n");
            return 0;
        }
        *e = sst->data[sst->top_right++];
    }
    return 1;

}

void printStack(SharedStack sst) {
    for(int i = 0; i <= sst.top_left; i++) {
        printf("%d-", sst.data[i]);
    }
    printf("\n");
    for(int i = sst.top_right; i < MAX_SIZE; i++) {
        printf("%d-", sst.data[i]);
    }
    printf("\n");
}


int main() {

    SharedStack st;
    st.top_left = -1;
    st.top_right = MAX_SIZE;
    push(0, &st, 1);
    push(0, &st, 2);

    push(0, &st, 3);
    push(1, &st, 5);
    push(1, &st, 6);
    push(1, &st, 7);
    printStack(st);
}


