//
// Created by han1254 on 4/24/21.
//

#include "common_header.h"
#include "stdlib.h"
#include "string.h"

int isLeft(char t) {
    switch (t) {
        case '(':
        case '[':
        case '{':
            return 1;
        case ')':
        case ']':
        case '}':
            return 0;
        default:
            printf("not a parentheses!\n");
            exit(0);
    }

}

int match(char left, char right) {
    if ((left == '(' && right == ')')
    || (left == '[' && right == ']')
    || (left == '{' && right == '}')) {
        return 1;
    }
    return 0;
}

int main() {
    Stack stack;
    InitStack(&stack);

    char *ch;
    ch = (char*)malloc(sizeof(char));
    scanf("%s", ch);
    int len = (int)strlen(ch);
    for (int i = 0; i < len; ++i) {
        char t = ch[i];
        if (isLeft(t)) {
            Push(&stack, t);
        } else {
            if (!match(GetTop(stack), t)) {
                printf("not match, stack top=%c, current ch=%c\n", GetTop(stack), t);
                return 0;
            }
            char res;
            Pop(&stack, &res);
        }
    }
    printf("match!\n");
}