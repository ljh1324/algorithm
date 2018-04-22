// https://www.acmicpc.net/problem/2292
// 흠 코드가 좀 복잡하지만 어쨋든 해결!

#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	if (n == 1)
	{
		printf("%d\n", 1);
	}
	else
	{
		int start = 2, end = 7;
		int cnt = 2;
		int jump = 6;
		int delta;
		int i = 1;
		while (!(start <= n && n <= end))
		{
			delta = i * jump;
			start += delta;
			i++;
			delta = i * jump;
			end = start + delta - 1;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
