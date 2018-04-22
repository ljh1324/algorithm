// https://www.acmicpc.net/problem/1065
// ÇØ°á

#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int one_num = 0;
	char str[4];

	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)
	{
		int temp = i;
		int len = 0;
		while (temp != 0)
		{
			str[len++] = temp % 10;
			temp /= 10;
		}

		if (len <= 2)
			one_num++;
		else
		{
			bool flag = true;
			int delta;

			delta = str[1] - str[0];
			for (int j = 2; j < len; ++j)
			{
				if (str[j] - str[j - 1] != delta)
				{
					flag = false;
					break;
				}
			}

			if (flag)
				one_num++;
		}
	}
	printf("%d\n", one_num);

	return 0;
}