//
// Created by han1254 on 4/24/21.
// 中缀表达式->后缀表达式
// 运行项目，输入例如：a+b*c#
// 结果为：abc*+
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
        printf("****************\n");
        printf("ch=%c\n", ch);
        printf("OPTR_STACk:");
        PrintStack(OPTR);
        if (!is_op(ch)) {
            Push(&RESULT, ch);
            ch = (char)getchar();
        } else {
            switch (precede(GetTop(OPTR), ch)) {
                case '<':
                    printf("OPTR.top <· %c, ch=%c enters the OPTR stack.\n", ch, ch);
                    Push(&OPTR, ch);
                    ch = (char)getchar();
                    break;
                case '='://脱括号并且接受下一个字符
                    printf("OPTR.top =·= %c, OPTR pop the top element.\n", ch);
                    Pop(&OPTR, &op);
                    ch = (char)getchar();
                    break;
                case '>':
                    printf("OPTR.top ·> %c, OPTR.top enters the Result stack.\n", ch);
                    Pop(&OPTR, &op);
                    Push(&RESULT, op);
                    break;
                default:
                    printf("error!\n");
                    exit(1);

            }
        }
        printf("Current RESULT_STACK:");
        PrintStack(RESULT);
        printf("****************\n");
    }
}

int main() {
    expression_change();
    PrintStack(RESULT);
}