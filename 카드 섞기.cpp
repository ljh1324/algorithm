// https://www.acmicpc.net/problem/1091
// 종료 조건을 좀 더 생각해봐야 겠음

#include <stdio.h>

int origin[48];
int card[48];
int s[48];
int n;

int simulate()
{
	int cnt = 0;
	int check = 0;
	int temp[48];

	for (int i = 0; i < n; ++i)
	{
		if (card[i] == i)
			check++;
		else break;
	}

	if (check >= n)
		return cnt;

	while (1)
	{
		for (int i = 0; i < n; ++i)
			temp[i] = card[i];
		
		for (int i = 0; i < n; ++i)
			card[s[i]] = temp[i];

		check = 0;
		for (int i = 0; i < n; ++i)
			if (card[i] == i)
				check++;
			else
				break;
		cnt++;
		if (check >= n)
			return cnt;

		bool same = true;
		for (int i = 0; i < n; ++i)
			if (card[i] != origin[i])
			{
				same = false;
				break;
			}

		if (same)
			return -1;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &card[i]);
		origin[i] = card[i];
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &s[i]);

	printf("%d\n", simulate());

	return 0;
}