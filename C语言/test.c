#include "stdio.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100 // the initial allocation of linear list storage space
#define LISTINCREMENT 10 // linear list storage space allocation increament
#define OK 1
#define ERROR 0

typedef struct {
	int* element; // 当前存储空间基址
	int length; // 当前长度
	int list_size; // 当前分配的存储容量（以sizeof(int)为单位）
}SqList;

void print_list_sq(SqList *l)
{
	for(int i = 0; i < l->length; i++)
	{
		printf("%d ", l->element[i]);
	}
	printf("\n");
}

int init_list_sq(SqList *l)
{
	l->element = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if(!l->element) return ERROR;
	l->length = 0;
	l->list_size = LIST_INIT_SIZE;
	return OK;

}

int list_insert_sq(SqList *l, int i, int element)
{
	// 插入的位置不能比最后一个的后一个还往后
	// 最后一个的位置为l->length - 1，那么你最后能插入的位置
	// 应该为l->length
	if(i < 0 || i > l->length)
	{
		return ERROR;
	}
	if(l->length >= l->list_size)
	{
		int* newbase = (int*)realloc(l->element, (l->list_size + LISTINCREMENT) * sizeof(int));
		if(!newbase)
			return ERROR;
		l->element = newbase;
		l->list_size += LISTINCREMENT;

	}

	int* q = l->element[i];
	for(int* p = (l->element[l->length - 1]); p >= q; p--)
		*(p + 1) = *p;
	*q = element;
	l->length++;
	return OK;
}

int main()
{
	SqList list_sq;
	if(init_list_sq(&list_sq) == 1)
	{
		printf("初始化线性表，基址：%p\n", &list_sq);
		printf("%d", sizeof(list_sq) / sizeof(int));
	}
	else
		printf("初始化失败。\n");
	list_insert_sq(&list_sq, 0, 8);
	print_list_sq(&list_sq);
}

