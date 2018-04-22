#include <stdio.h>
// ÇØ°á^^

int main()
{
	int n;
	scanf("%d", &n);
	int last = n / 100;
	bool flag = false;

	int i;
	for (i = last; i <= n - 1; ++i)
	{
		int temp = i;
		int sum = temp;

		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n)
		{
			flag = true;
			break;
		}
	}

	if (!flag)
		printf("%d", 0);
	else
		printf("%d", i);

	return 0;
}