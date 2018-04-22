// https://www.acmicpc.net/problem/2740
// 해결.... 더 빠른 알고리즘은
// https://ko.wikipedia.org/wiki/%EC%8A%88%ED%8A%B8%EB%9D%BC%EC%84%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

#include <stdio.h>

int main()
{
	int mat1[100][100], mat2[100][100];
	int result[100][100];

	int n, m, k;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &mat1[i][j]);
	
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < k; ++j)
			scanf("%d", &mat2[i][j]);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
		{
			int sum = 0;
			for (int l = 0; l < m; ++l)
			{
				sum += mat1[i][l] * mat2[l][j];
			}
			result[i][j] = sum;
		}

	for (int i = 0; i < n; ++i)
	{ 
		for (int j = 0; j < k; ++j)
			printf("%d ", result[i][j]);
		printf("\n");
	}
	return 0;
}
