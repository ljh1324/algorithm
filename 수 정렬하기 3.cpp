// https://www.acmicpc.net/problem/10989

#include <stdio.h>

int main()
{
	int count[10001] = { 0, };

	int n, value, max, min;
	scanf("%d", &n);

	max = 0; min = 10000;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &value);
		count[value]++;
		if (value > max)
			max = value;
		else if (value < min)
			min = value;
	}

	for (int i = min; i <= max; ++i)
		for (int j = 0; j < count[i]; ++j)
			printf("%d\n", i);

	return 0;
}