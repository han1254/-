//
// Created by han1254 on 4/19/21.
//

#include "LinkStackImpl.h"

int main() {
    LinkStack stack;
    Init_Link_Stack(&stack);
    if (Is_Empty_Link_Stack(stack) == 1) printf("Stack is Empty\n");
    Push_Link_Stack(stack, 1);
    Push_Link_Stack(stack, 3);
    Push_Link_Stack(stack, 5);
    Print_Stack_Link_Stack(stack);
}

