// https://www.acmicpc.net/problem/11004
// 분할 정복 해버렸으~~~~

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int sort(int* arr, int left, int right)
{
	if (right - left < 1)
		return left;

	int rand_idx = rand() % (right - left + 1);
	int pivot = arr[left + rand_idx];				// 피봇을 정한다.
	swap(arr[left], arr[left + rand_idx]);			// 피봇을 가장 왼쪽에 둔다.

	int i = left, j = right + 1;
	do
	{
		do
		{
			i++;
		} while (arr[i] < pivot && i <= right);     // 만약 i가 피봇보다 커질 때 까지 i를 증가시켜 준다.

		do
		{
			j--;
		} while (arr[j] > pivot);					// 만약 j가 피봇보다 작아질 때 까지 j를 감소시켜 준다.

		if (i >= j)
			break;

		swap(arr[i], arr[j]);						// i와 j를 바꿔준다.
	} while (1);

	swap(arr[j], arr[left]);						// j는 피봇보다 작으므로 피봇 왼쪽에 가야하므로 바꿔주어도 상관없다.
	
	return j;
}

int main()
{
	srand(time(NULL));

	int arr[5000000];
	
	int n, rank;
	int left;
	int right;
	int pivot;

	scanf("%d %d", &n, &rank);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	rank = rank - 1;
	left = 0;
	right = n - 1;

	do
	{
		pivot = sort(arr, left, right);
		if (pivot == rank)
			break;
		else if (pivot > rank)
		{
			right = pivot - 1;
		}
		else if (pivot < rank)
		{
			left = pivot + 1;
		}
	} while (1);

	printf("%d\n", arr[pivot]);
}