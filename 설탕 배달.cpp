// https://www.acmicpc.net/problem/2839

/*
// 4999일 경우 처리를 하지 못함..
#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	int cnt = n / 15;
	cnt *= 3;
	n %= 15;

	if (n != 0)
	{
		bool flag = false;
		for (int i = 2; i >= 0; --i)
		{
			if (n >= (i * 5))
			{ 
				int temp = n - (i * 5);
				if (temp % 3 == 0)
				{
					cnt += i;
					n -= (i * 5);
					cnt += n / 3;
					flag = true;
					break;
				}
			}
		}

		if (flag)
			printf("%d\n", cnt);
		else
			printf("%d\n", -1);
	}
	else
		printf("%d\n", cnt);
	return 0;
}

*/

// 해결^^
#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	int start = n / 5;
	int cnt;
	bool flag = false;
	for (int i = start; i >= 0; --i)
	{
		int temp = n;
		cnt = i;
		temp -= i * 5;
		if (temp % 3 == 0)
		{
			flag = true;
			cnt += temp / 3;
			break;
		}
	}
	
	if (flag)
	{
		printf("%d\n", cnt);
	}
	else
		printf("%d\n", -1);

	return 0;
}