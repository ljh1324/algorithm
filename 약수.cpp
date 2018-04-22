// https://www.acmicpc.net/problem/1037

#include <stdio.h>

int main()
{
	int n;
	int value;
	int min, max;

	scanf("%d", &n);
	min = 1000001;
	max = -1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &value);
		if (value > max)
			max = value;
		if (value < min)
			min = value;
	}

	if (n == 1)
	{
		printf("%d\n", value * value);
	}
	else
		printf("%d\n", min * max);
	
	return 0;
}