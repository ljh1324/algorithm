// https://www.acmicpc.net/problem/1071
// ���� �����

#include <stdio.h>

int arr[50];
int n;
int max;
bool check[50];
int min_idx;
int min;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			check[j] = true;
		
		// j �ڿ� ���� �� Ž��
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] + 1 == arr[i])
				check[j] = false;
			if (j < i - 1 && arr[i] + 1 == arr[j + 1])
				check[j] = false;
		}


	}
	return 0;
}