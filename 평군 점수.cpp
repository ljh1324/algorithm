// https://www.acmicpc.net/problem/10039
// ÇØ°á

#include <stdio.h>

int main()
{
	int sum = 0;
	int value;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &value);
		if (value < 40)
			sum += 40;
		else
			sum += value;
	}

	printf("%d", sum / 5);

	return 0;
}