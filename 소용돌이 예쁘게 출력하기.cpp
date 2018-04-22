// https://www.acmicpc.net/problem/1022

// 흠.. 메모리 초과가 될듯..

#include <iostream>

using namespace std;

int matrix[10001][10001];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y)
{
	return 0 <= x && x <= 10000 && 0 <= y && y <= 10000;
}

void draw()
{
	memset(matrix, 0, sizeof(matrix));

	int x = 5000, y = 5000;
	int dir = 3;
	int num = 1;
	matrix[y][x] = 1;

	while (1)
	{
		bool flag = false;
		int cnt = 0;
		int nextDir = (dir + 1) % 4;

		int nextX = x + dx[nextDir];
		int nextY = y + dy[nextDir];
		if (inRange(nextX, nextY) && matrix[nextY][nextX] == 0)
		{
			dir = nextDir;
			matrix[nextY][nextX] = ++num;
		}
		else 
		{
			nextX = x + dx[dir];
			nextY = y + dy[dir];
			if (inRange(nextX, nextY) && matrix[nextY][nextX] == 0)
				matrix[nextY][nextX] = ++num;
			else  // 더 이상 진행할 곳이 없다.
				break;
		}
		x = nextX;
		y = nextY;
	}
}

int main()
{
	draw();

	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	r1 += 5000;
	c1 += 5000;
	r2 += 5000;
	c2 += 5000;

	int max = 0;
	char buff[10];
	for (int i = r1; i <= r2; ++i)
		for (int j = c1; j <= c2; ++j)
			if (max < matrix[i][j])
				max = matrix[i][j];
	int log = log10(max) + 1;

	sprintf(buff, "%%%dd ", log);
	// printf("%s", buff);

	for (int i = r1; i <= r2; ++i)
	{ 
		for (int j = c1; j <= c2; ++j)
		{
			printf(buff, matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
