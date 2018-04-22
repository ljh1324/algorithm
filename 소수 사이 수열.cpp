// https://www.acmicpc.net/problem/3896

#include <stdio.h>

bool* primeArray;

void eratos(int n)
{
	primeArray = new bool[n * 2 + 1];
	primeArray[0] = false;
	primeArray[1] = false;

	for (int i = 2; i <= n * 2; ++i)
		primeArray[i] = true;

	for (int i = 2; i * i <= n * 2; ++i)
		if (primeArray[i])
			for (int j = i * i; j <= n * 2; j += i) primeArray[j] = false;
}

int find_boundary_length(int n)
{
	if (primeArray[n])
		return 0;

	int after;
	int before;
	for (after = n + 1; !primeArray[after]; after++);
	for (before = n - 1; !primeArray[before]; before--);
	
	if (before <= 1)
		return 0;

	return after - before;
}

int main()
{
	int tc;
	int* arr;
	int max = 0;

	scanf("%d", &tc);
	arr = new int[tc];
	for (int i = 0; i < tc; ++i)
	{
		scanf("%d", arr + i);
		if (arr[i] > max)
			max = arr[i];
	}
	eratos(max);

	for (int i = 0; i < tc; ++i)
	{
		printf("%d\n", find_boundary_length(arr[i]));
	}
	return 0;
}