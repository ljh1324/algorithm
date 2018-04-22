// https://www.acmicpc.net/problem/1008

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%0.20f", a / (double)b);

	return 0;
}