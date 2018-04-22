// https://www.acmicpc.net/problem/1081
// time out

#include <stdio.h>
#include <string.h>

int sum[1000];

int cal_sum(int want)
{
	if (sum[want] != -1)
		return sum[want];

	int result = 0;
	while (want != 0)
	{
		result += want % 10;
		want /= 10;
	}

	sum[want] = result;

	return result;
}

int main()
{
	int start, end;
	int val;
	int result;
	memset(sum, -1, 1000);

	scanf("%d %d", &start, &end);

	result = 0;
	for (int i = start; i <= end; ++i)
	{
		val = i;
		while (val != 0)
		{
			result += cal_sum(val % 1000);
			val /= 1000;
		}
	}

	printf("%d\n", result);

	return 0;
}