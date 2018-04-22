// https://www.acmicpc.net/problem/2577

#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int result = a * b * c;
	int arr[10] = { 0, };

	do
	{
		arr[result % 10]++;
		result /= 10;
	} while (result != 0);

	for (int i = 0; i < 10; ++i)
		printf("%d\n", arr[i]);

	return 0;
}