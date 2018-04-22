// https://www.acmicpc.net/problem/2309
// ÇØ°á

#include <stdio.h>
#include <algorithm>

int arr[9];
int flag = false;

int comparator(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

void brute_force(int n, bool selected[9])
{
	if (flag)
		return;

	if (n == 0)
	{
		int sum = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (selected[i])
				sum += arr[i];
		}

		if (sum == 100)
		{
			int hobit[7];
			int idx = 0;
			for (int i = 0; i < 9; ++i)
				if (selected[i])
					hobit[idx++] = arr[i];
			qsort(hobit, 7, sizeof(int), comparator);
			
			for (int i = 0; i < 7; ++i)
				printf("%d\n", hobit[i]);
			flag = true;
		}

		return;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (!selected[i])
		{
			selected[i] = true;
			brute_force(n - 1, selected);
			selected[i] = false;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		scanf("%d", &arr[i]);
	}

	bool selected[9] = { false, };

	brute_force(7, selected);

	return 0;
}