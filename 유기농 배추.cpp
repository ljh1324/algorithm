// https://www.acmicpc.net/problem/1012

#include <stdio.h>

using namespace std;

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

int count;
int width, height, k;
int matrix[50][50];

void init(int width, int height) {
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			matrix[i][j] = 0;
}

void moveWarm(int x, int y) {
	matrix[y][x] = -1;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < 0 || nextX >= width || nextY < 0 || nextY >= height)
			continue;

		if (matrix[nextY][nextX] == 1)
			moveWarm(nextX, nextY);
	}
}

int main()
{
	int tc;
	int x, y;

	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%d %d %d", &width, &height, &k);
		init(width, height);

		for (int j = 0; j < k; ++j)
		{
			scanf("%d %d", &x, &y);
			matrix[y][x] = 1;
		}

		count = 0;
		for (int j = 0; j < height; ++j)
			for (int k = 0; k < width; ++k)
			{
				if (matrix[j][k] == 1)
				{
					count++;
					moveWarm(k, j);
				}
			}
		printf("%d\n", count);
	}

	return 0;
}