// https://www.acmicpc.net/problem/1213

#include <stdio.h>
#include <string.h>

int main()
{
	char str[51];
	int alphabet[26] = { 0, };
	int alphabet_count = 0;

	scanf("%s", str);
	for (int i = 0; i < strlen(str); ++i)
	{
		alphabet[str[i] - 'A']++;
	}

	int odd_count = 0;
	int odd_idx = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] % 2 == 1)
		{
			odd_count++;
			odd_idx = i;
		}
	}

	if (odd_count > 1)
		printf("I'm Sorry Hansoo\n");
	else
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < alphabet[i] / 2; ++j)
			{
				printf("%c", i + 'A');
			}
		}

		if (odd_idx != -1)
		{
			printf("%c", odd_idx + 'A');
		}

		for (int i = 25; i >= 0; --i)
		{
			for (int j = 0; j < alphabet[i] / 2; ++j)
			{
				printf("%c", i + 'A');
			}
		}
		printf("\n");
	}
	return 0;
}