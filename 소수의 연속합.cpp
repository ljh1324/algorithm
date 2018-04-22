// https://www.acmicpc.net/problem/1644

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

bool* primeArray;
queue<int> numbers;

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
	int n;
	scanf("%d", &n);
	eratos(n);

	int sum = 0;
	int count = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (primeArray[i])
		{
			sum += i;
			numbers.push(i);
			while (!numbers.empty() && sum  > n)
			{
				sum -= numbers.front();
				numbers.pop();
			}
			if (sum == n)
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}