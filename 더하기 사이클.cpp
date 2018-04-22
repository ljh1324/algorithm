// https://www.acmicpc.net/problem/1110

#include <stdio.h>

int main()
{
	int origin;
	int n, cnt;

	scanf("%d", &origin);
	n = origin;
	cnt = 0;

	do
	{
		n = (n % 10) * 10 + (((n / 10) + (n % 10)) % 10);
		cnt++;
	} while (origin != n);

	printf("%d\n", cnt);

	return 0;
}