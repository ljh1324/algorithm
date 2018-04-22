// https://www.acmicpc.net/problem/1026

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void swap(int& a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void my_qsort_ascend(int* arr, int start, int end) {

	if (end - start <= 0) return;

	srand(time(NULL));

	int pivot_idx = rand() % (end - start + 1) + start;
	int pivot = arr[pivot_idx];
	swap(arr[start], arr[pivot_idx]);

	int i = start;
	int j = end + 1;

	do
	{
		do {
			i++;
		} while (i <= end && arr[i] < pivot);
		do {
			j--;
		} while (j >= start + 1 && arr[j] > pivot);

		if (i >= j) break;
		swap(arr[i], arr[j]);
	} while (1);
	swap(arr[start], arr[j]);

	my_qsort_ascend(arr, start, j - 1);
	my_qsort_ascend(arr, j + 1, end);
}

void my_qsort_descend(int* arr, int start, int end) {

	if (end - start <= 0) return;

	srand(time(NULL));

	int pivot_idx = rand() % (end - start + 1) + start;
	int pivot = arr[pivot_idx];
	swap(arr[start], arr[pivot_idx]);

	int i = start;
	int j = end + 1;

	do
	{
		do {
			i++;
		} while (i <= end && arr[i] > pivot);
		do {
			j--;
		} while (j >= start + 1 && arr[j] < pivot);

		if (i >= j) break;
		swap(arr[i], arr[j]);
	} while (1);
	swap(arr[start], arr[j]);

	my_qsort_descend(arr, start, j - 1);
	my_qsort_descend(arr, j + 1, end);
}

int main()
{
	int n;
	int a[50], b[50];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b[i]);
	}

	my_qsort_ascend(a, 0, n - 1);
	my_qsort_descend(b, 0, n - 1);

	int min = 0;
	for (int i = 0; i < n; ++i)
	{
		min += a[i] * b[i];
	}

	printf("%d\n", min);

	return 0;
}