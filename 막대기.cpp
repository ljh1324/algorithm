// https://www.acmicpc.net/problem/1094

#include <stdio.h>

int main()
{
	int x;
	// int sum = 0;
	int count= 0;
	// int stick = 64;

	scanf("%d", &x);

	/*
	while (sum != x)
	{
		if (sum + stick <= x)
		{
			sum += stick;
			count++;
		}
		stick /= 2;
	}
	*/

	while (x != 0)
	{
		count += x & 1;
		x = x >> 1;
	}
	printf("%d\n", count);
	return 0;
}