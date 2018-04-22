// https://www.acmicpc.net/problem/1111#
// 중간에 틀린 답

#include <stdio.h>

int n;
int arr[50];

int main()
{
	int a, b;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	if (n <= 2)
		printf("A\n");
	else
	{
		if (arr[0] != arr[1])
		{
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
			b = (arr[1] - arr[0] * a);
		}
		else
		{
			a = 0;
			b = arr[0];
		}

		bool check = true;
		for (int i = 3; i < n; ++i)
			if (arr[i - 1] * a + b != arr[i]) {
				check = false;
				break;
			}

		if (check)
			printf("%d\n", arr[n - 1] * a + b);
		else
			printf("B\n");
	}

	return 0;
}