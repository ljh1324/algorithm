// https://www.acmicpc.net/problem/7469
// ���� �ð� �ʰ�..

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
	int pivot = arr[left + rand_idx];				// �Ǻ��� ���Ѵ�.
	swap(arr[left], arr[left + rand_idx]);			// �Ǻ��� ���� ���ʿ� �д�.

	int i = left, j = right + 1;
	do
	{
		do
		{
			i++;
		} while (arr[i] < pivot && i <= right);     // ���� i�� �Ǻ����� Ŀ�� �� ���� i�� �������� �ش�.

		do
		{
			j--;
		} while (arr[j] > pivot);					// ���� j�� �Ǻ����� �۾��� �� ���� j�� ���ҽ��� �ش�.

		if (i >= j)
			break;

		swap(arr[i], arr[j]);						// i�� j�� �ٲ��ش�.
	} while (1);

	swap(arr[j], arr[left]);						// j�� �Ǻ����� �����Ƿ� �Ǻ� ���ʿ� �����ϹǷ� �ٲ��־ �������.

	return j;
}

int main()
{
	srand(time(NULL));

	int arr[100000];
	int sub_arr[100000];

	int n, m;
	int left;
	int right;
	int pivot;
	int rank;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	
	for (int i = 0; i < m; ++i)
	{ 
		scanf("%d %d %d", &left, &right, &rank);
		left -= 1;
		right -= 1;
		rank -= 1;

		int idx = 0;
		for (int j = left; j <= right; ++j)
			sub_arr[idx++] = arr[j];

		left = 0;
		right = idx - 1;

		do
		{
			pivot = sort(sub_arr, left, right);
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

		printf("%d\n", sub_arr[pivot]);
	}
}