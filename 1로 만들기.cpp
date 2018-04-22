// https://www.acmicpc.net/problem/1463
// 동적 프로그래밍 개쉽노 ^^

#include <stdio.h>

int dp[1000001];

int operation(int n)
{
	if (n == 1)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int min = 1 + operation(n - 1);
	if (n % 2 == 0)
	{
		int value = operation(n / 2);
		if (min > 1 + value)
		{
			min = 1 + value;
		}
	}
	if (n % 3 == 0)
	{
		int value = operation(n / 3);
		if (min > 1 + value)
		{
			min = 1 + value;
		}
	}
	dp[n] = min;

	return dp[n];
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", operation(n));

	return 0;
}