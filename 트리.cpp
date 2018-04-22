// https://www.acmicpc.net/problem/1068

#include <stdio.h>

int matrix[50][50];
int n;

int count_leaf(int start, bool is_root)
{
	int check = false;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (matrix[start][i])
		{
			check = true;
			cnt += count_leaf(i, false);
		}
	}
	if (!check && !is_root)		// 리프일 경우
		cnt = 1;

	return cnt;
}

int main()
{
	int parent;
	int root;
	int remove;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &parent);
		if (parent == -1)
			root = i;
		else
			matrix[parent][i] = 1;
	}
	scanf("%d", &remove);
	for (int i = 0; i < n; ++i)
	{
		matrix[i][remove] = 0;
		matrix[remove][i] = 0;
	}

	printf("%d\n", count_leaf(root, true));
	return 0;
}