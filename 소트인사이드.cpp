// https://www.acmicpc.net/problem/1427
// ÇØ°á ^^

#include <stdio.h>
#include <string.h>

int main()
{
	char str[11];
	int num[10] = { 0, };

	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		num[str[i] - '0']++;
	}

	int index = 0;
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 0; j < num[i]; ++j)
			str[index++] = i + '0';
	}

	printf("%s\n", str);

	return 0;
}