// https://www.acmicpc.net/problem/1929

#include <stdio.h>

bool* primeArray;

void eratos(int n)
{
	if (n <= 1) return;

	primeArray = new bool[n + 1];
	primeArray[0] = primeArray[1] = false;

	for (int i = 2; i <= n; ++i)
		primeArray[i] = true;

	for (int i = 2; i * i <= n; ++i)
	{
		if (primeArray[i])
			for (int j = i * i; j <= n; j += i) primeArray[j] = false;
	}
}

int main()
{
	int start, end;

	scanf("%d %d", &start, &end);

	eratos(end);

	int cnt = 0;
	for (int i = start; i <= end; ++i)
		if (primeArray[i])
			printf("%d\n", i);
}