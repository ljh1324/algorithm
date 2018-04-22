// https://www.acmicpc.net/problem/1239
// 해결!!!!!

#include <stdio.h>

bool visited[8];
int arr[8];
int ratio[8];
int size;
int max;

void brute(int n)
{
	if (n == size)
	{
		int line = 0;
		int sum = 0;
		int start = 0;
		for (int i = 0; i < size; ++i)
		{
			sum += ratio[arr[i]];
			if (sum == 50)
			{
				line++;
			}

			while (sum >= 50)
			{
				sum -= ratio[arr[start]];
				start++;
			}
		}
		line--;

		if (line > max)
			max = line;
	}

	for (int i = 0; i < size; ++i)
	{	// 전체 경우의 수를 만든다.
		if (!visited[i])
		{
			arr[n] = i;
			visited[i] = true;
			brute(n + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; ++i)
		scanf("%d", &ratio[i]);

	brute(0);
	printf("%d\n", max);
	return 0;
}