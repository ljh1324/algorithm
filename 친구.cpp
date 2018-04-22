// https://www.acmicpc.net/problem/1058

#include <stdio.h>

char matrix[50][51];
bool be_friend[50];
int friend_n;
int count;
int max;

void count_friend(int start, int cur, int depth)
{
	if (max == friend_n - 1)
		return;

	if (depth == 2)
	{
		return;
	}

	for (int i = 0; i < friend_n; ++i)
		if (i != start && matrix[cur][i] == 'Y')
		{
			count_friend(start, i, depth + 1);
			if (!be_friend[i])
			{
				count++;
				be_friend[i] = true;
			}
		}
}

int main()
{
	char input[51];

	scanf("%d", &friend_n);
	
	for (int i = 0; i < friend_n; ++i)
	{
		scanf("%s", matrix[i]);
	}
	
	int max = 0;
	for (int i = 0; i < friend_n; ++i)
	{
		for (int i = 0; i < friend_n; ++i)
			be_friend[i] = false;

		count = 0;
		count_friend(i, i, 0);
		if (max < count)
			max = count;
	}

	printf("%d\n", max);
	return 0;
}