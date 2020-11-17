#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int start, int end);
int partiton(int *arr, int start, int end);

int main(int argc, char const *argv[])
{
	int a[10] = {5, 9, 4, 7, 6, 3, 8, 10, 2, 1};
	quickSort(a, 0, 9);
	printf("final result:\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

/**
 * 快速排序
 * @param arr   [description]
 * @param start [description]
 * @param end   [description]
 */
void quickSort(int *arr, int start, int end)
{
	if (start == end)
	{
		return;
	}

	int index = partiton(arr, start, end);
	printf("index position = %d\n", index);
	printf("current array: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	if (index > start)
	{
		quickSort(arr, start, index - 1);
	}
	if (index < end)
	{
		quickSort(arr, index + 1, end);
	}
}

int partiton(int *arr, int start, int end)
{
	if (start == end)
	{
		return start;
	}
	int pivot = arr[start];
	int i = start;
	int j = end;
	while(i < j)
	{
		while(i < j && arr[j] > pivot)
		{
			j--;
		}
		while(i < j && arr[i] <= pivot)
		{
			i++;
		}
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	int temp = arr[i];
	arr[i] = arr[start];
	arr[start] = temp;
	return i;
}