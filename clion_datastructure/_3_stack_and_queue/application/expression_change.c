//
// Created by han1254 on 4/24/21.
// 终追表达式
//

#include <stdlib.h>
#include "common_header.h"
static Stack OPTR;
static Stack OPEND;
static Stack RESULT;

int is_op(char t) {
    if (t == '+' || t == '-' || t == '*'
    || t == '/' || t == '(' || t == ')'||t == '#') return 1;
    return 0;
}

char precede(char op1, char op2) {
    if (!is_op(op1) || !is_op(op2)) {
        printf("not a operator!\n");
        exit(1);
    }
    switch (op1) {
        case '+':
        case '-':
            switch (op2) {
                case '+':
                case '-':
                case ')':
                case '#':
                    return '>';
                case '*':
                case '/':
                case '(':
                    return '<';
                default:
                    printf("error!\n");
                    exit(1);

            }
        case '*':
        case '/':
            switch (op2) {
                case '+':
                case '-':
                case '*':
                case '/':
                case ')':
                case '#':
                    return '>';
                case '(':
                    return '<';
                default:
                    printf("error, %c with %c\n", op1, op2);
                    exit(1);

            }
        case '(':
            switch (op2) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                    return '<';
                case ')':
                    return '=';
                default:
                    printf("error, %c with %c\n", op1, op2);
                    exit(1);
            }
        case ')':
            switch (op2) {
                case '+':
                case '-':
                case '*':
                case '/':
                case ')':
                case '#':
                    return '>';
                default:
                    printf("error, %c with %c\n", op1, op2);
                    exit(1);
            }
        case '#':
            switch (op2) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case '#':
                    return '<';
                default:
                    printf("error, %c with %c\n", op1, op2);
                    exit(1);
            }
        default:
            printf("error, %c with %c\n", op1, op2);
            exit(1);
    }
}


void expression_change() {
    InitStack(&RESULT);
    InitStack(&OPTR);
    InitStack(&OPEND);

    Push(&OPTR, '#');

    char ch = (char)getchar();
    char op;
    while (ch != '#' || (!StackEmpty(OPTR) && GetTop(OPTR) != '#')) {
        if (!is_op(ch)) {
            Push(&RESULT, ch);
            ch = (char)getchar();
        } else {
            switch (precede(GetTop(OPTR), ch)) {
                case '<':
                    Push(&OPTR, ch);
                    ch = (char)getchar();
                    break;
                case '='://脱括号并且接受下一个字符
                    Pop(&OPTR, &op);
                    ch = (char)getchar();
                    break;
                case '>':
                    Pop(&OPTR, &op);
                    Push(&RESULT, op);
                    break;
                default:
                    printf("error!\n");
                    exit(1);

            }
        }
    }
}

int main() {
    expression_change();
    PrintStack(RESULT);
}