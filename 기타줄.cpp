// https://www.acmicpc.net/problem/1049
// ¸ø Ç®À½

#include <stdio.h>

int main()
{
	int line_n, brand_n;
	int pack_min, one_min;
	int pack_money, one_money;

	scanf("%d %d", &line_n, &brand_n);
	pack_min = one_min = 987654321;
	for (int i = 0; i < brand_n; ++i)
	{
		scanf("%d %d", &pack_money, &one_money);
		if (pack_min > pack_money)
			pack_min = pack_money;
		if (one_min > one_money)
			one_min = one_money;
	}

	int min;
	if (pack_min > one_min * 6)
		printf("%d\n", one_min * line_n);
	else
	{
		min = pack_min * (int)(line_n / 6) + one_min * (line_n % 6);
		if (min > pack_min * (line_n / 6 + 1))
			min = pack_min * (line_n / 6 + 1);
		printf("%d\n", min);
	}

	return 0;
}