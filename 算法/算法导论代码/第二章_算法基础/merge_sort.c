#include <stdio.h>
#include <limits.h>
void merge1(int* A, int p, int q, int r);
void merge2(int* A, int p, int q, int r);
void merge_sort(int *A, int p, int r);

int main(int argc, char const *argv[])
{
	int t[10] = {10, 2, 3, 9, 5, 8, 7, 6, 4, 1};
	merge_sort(t, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", t[i]);
	}
	return 0;
}
//《算法导论》中文版第三版 p30 2.3.1 分治法 归并排序
void merge_sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge1(A, p, q, r);
	}
}

/**
 * 使用哨兵的合并算法
 * @param A 目的数组
 * @param p 开始位置
 * @param q 第一组的结束位置
 * @param r 第二组的结束位置
 */
void merge1(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1 + 1];
	int R[n2 + 1];

	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[p + i];
	}

	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[q + i + 1];
	}

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int l_index = 0;
	int r_index = 0;

	for (int k = p; k <= r; ++k)
	{
		if (L[l_index] <= R[r_index])
		{
			A[k] = L[l_index];
			l_index = l_index + 1;
		}
		else 
		{
			A[k] = R[r_index];
			r_index = r_index + 1;
		}
	}
}

/**
 * 不使用哨兵的合并算法
 * @param A 目的数组
 * @param p 第一组开始位置
 * @param q 第一组结束位置
 * @param r 第二组结束位置
 */
void merge2(int* A, int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1];
	int R[n2];

	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[p + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[q + i + 1];
	}

	int l_index = 0;
	int r_index = 0;

	for (int k = p; k <= r; ++k)
	{
		if (l_index >= n1)
		{
			A[k] = R[r_index];
			r_index = r_index + 1;
		} 
		else if (r_index >= n2)
		{
			A[k] = L[l_index];
			l_index = l_index + 1;
		}
		else if (L[l_index] <= R[r_index])
		{
			A[k] = L[l_index];
			l_index = l_index + 1;
		} 
		else
		{
			A[k] = R[r_index];
			r_index = r_index + 1;
		}
	}
}