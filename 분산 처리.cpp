#include <stdio.h>

int main()
{
	int numOfCase;
	int a, b, result;
	scanf("%d", &numOfCase);

	for (int i = 0; i < numOfCase; ++i)
	{
		scanf("%d %d", &a, &b);

		result = 1;
		for (int i = 0; i < b; ++i)
		{
			result *= a;
			result %= 10;		// 끝의 자리 수만 보면 되므로.
		}

		if (result == 0)
			result = 10;
		printf("%d\n", result);
	}

	return 0;
}