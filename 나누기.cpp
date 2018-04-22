// https://www.acmicpc.net/problem/1075

#include <stdio.h>

int main()
{
	int n, f;
	int temp;
	int remainder;
	int min = 100;

	scanf("%d", &n);
	scanf("%d", &f);

	remainder = n % f;

	temp = n % 100;
	temp += (f - remainder);
	while (temp < 100)
	{
		if (min > temp)
			min = temp;
		temp += f;
	}

	temp = n % 100;
	temp -= remainder;
	while (temp >= 0)
	{
		if (min > temp)
			min = temp;
		temp -= f;
	}

	printf("%02d\n", min);

	return 0;
}