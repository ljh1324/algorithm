// https://www.acmicpc.net/problem/10253
// 시간초과

#include <stdio.h>

int main()
{
	int tc;
	int a, b;
	int x;

	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%d %d", &a, &b);
		
		x = 2;
		while(1)
		{
			if (x * a >= b)
			{
				a = a * x;
				a -= b;
				b = b * x;
			}
			
			if (a == 0)
				break;
			x++;
		}

		printf("%d\n", x);
	}

	return 0;
}