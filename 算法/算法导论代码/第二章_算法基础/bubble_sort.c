#include <stdio.h>

void bubble_sort(int* A, int length);
void bubble_sort2(int* A, int length);


int main(int argc, char const *argv[])
{
	int t[16] = {10, 2, 3, 9, 5, 8, 7, 6, 4, 1, 225, 78, 69, 32, 90, 18};
	int length = sizeof(t) / sizeof(int);
	bubble_sort2(t, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", t[i]);
	}
	printf("\n");
	return 0;
}

//《算法导论》中文版第三版 p40 题目2-2 冒泡排序
void bubble_sort(int* A, int length) 
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = length - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}
//补充：冒泡排序的常用写法（个人意见）
void bubble_sort2(int* A, int length) {
	for (int i = 1; i < length; ++i)
	{
		for (int j = 0; j < length - i; j++) 
		{
			if (A[j + 1] < A[j])
			{
				int temp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = temp;
			}
		}
	}
}