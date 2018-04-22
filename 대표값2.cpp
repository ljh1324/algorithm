// https://www.acmicpc.net/problem/2587
// Çì°á!

#include <stdio.h>
#include <algorithm>

int comparator(const void* a, const void* b)
{
	if (*(int*)a > *(int *)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main()
{
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	qsort(arr, 5, sizeof(int), comparator);

	printf("%d\n", sum / 5);
	printf("%d\n", arr[2]);

	return 0;
}