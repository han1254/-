#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10
#include<string.h>
void main() {
	char str[N];
	char str1[N];
	char str2[N];
	printf("请输入字符串str\n");
	fgets(str, N, stdin);
	printf("请输入字符串str1\n");
	fgets(str1, N, stdin);
	printf("请输入字符串str2\n");
	fgets(str2, N, stdin);
	printf("str为:\n%s\n", str);
	printf("str1为:\n%s\n", str1);
	printf("str2为:\n%s\n", str2);
	system("pause");
}

