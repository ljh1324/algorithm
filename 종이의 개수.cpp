// https://www.acmicpc.net/problem/1780
// 어이가 없는 곳에서 틀렸구만... 어쨋든 해결 ^오^

#include <stdio.h>

int arr[2187][2187];

struct Paper
{
	int black, gray, white;
	Paper() : black(0), gray(0), white(0) {}
};

Paper countPaper(int startX, int startY, int size)
{
	int val = arr[startY][startX];
	bool flag = false;

	for (int i = startY; i < startY + size; ++i)
	{
		for (int j = startX; j < startX + size; ++j)
			if (arr[i][j] != val)
			{
				flag = true;
				break;
			}
		if (flag) break;
	}
	Paper paper = Paper();
	if (flag)
	{
		int partition = size / 3;
		for (int y = startY; y < startY + size; y += partition)
		{
			for (int x = startX; x < startX + size; x += partition)
			{
				Paper partitionPaper = countPaper(x, y, partition);
				paper.black += partitionPaper.black;
				paper.gray += partitionPaper.gray;
				paper.white += partitionPaper.white;
			}
		}
	}
	else
	{
		if (val == -1)
			paper.black = 1;
		else if (val == 0)
			paper.gray = 1;
		else
			paper.white = 1;
	}

	return paper;
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &arr[i][j]);

	Paper paper = countPaper(0, 0, n);

	printf("%d\n", paper.black);
	printf("%d\n", paper.gray);
	printf("%d\n", paper.white);

	return 0;
}