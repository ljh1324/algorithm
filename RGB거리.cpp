// https://www.acmicpc.net/problem/1149
// 꺄 동적프로그래밍 해결!

#include <stdio.h>
#include <string.h>

int n;
int dp[3][1000];
int cost[1000][3];

int paint(int home, int color)
{
	if (home == n)
		return 0;

	if (dp[color][home] != -1)
		return dp[color][home];

	int min = -1;
	int total;

	for (int i = 0; i < 3; ++i)
	{
		if (color != i)
		{
			total = cost[home][i] + paint(home + 1, i);
			if (min == -1)
				min = total;
			else if (min > total)
				min = total;
		}
	}
	dp[color][home] = min;
	return min;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

	int min = -1;
	int total = 0;
	for (int i = 0; i < 3; ++i)
	{
		total = paint(1, i) + cost[0][i];
		if (min == -1)
			min = total;
		else if (min > total)
			min = total;
	}
	printf("%d\n", min);

	return 0;
}