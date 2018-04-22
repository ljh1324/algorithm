// https://www.acmicpc.net/problem/1074

#include <stdio.h>
#include <math.h>

int main()
{
	int n, r, c;
	int count = 0;

	scanf("%d %d %d", &n, &r, &c);
	int side_length = pow(2, n);

	do {
		int standard = side_length / 2;
		if (r >= standard)
		{
			count += side_length * standard;
			r -= standard;
		}
		if (c >= standard)
		{
			count += standard * standard;
			c -= standard;
		}
		side_length /= 2;
	} while (side_length != 1);

	printf("%d\n", count);

	return 0;
}