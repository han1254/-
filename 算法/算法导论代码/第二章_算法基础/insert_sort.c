#include <stdio.h>
void insert_sort(int* arr, int length);

int main(int argc, char const *argv[])
{
	int t[10] = {10, 2, 3, 9, 5, 8, 7, 6, 4, 1};
	insert_sort(t, sizeof(t) / sizeof(int));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", t[i]);
	}
	return 0;
}

//《算法导论》中文版第三版 p17 2.1插入排序
void insert_sort(int *arr, int length)
{
	for (int i = 1; i < length; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}