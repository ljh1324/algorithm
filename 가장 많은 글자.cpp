// https://www.acmicpc.net/problem/1371

#include <stdio.h>
#include <string.h>
#define NULL 0

int main()
{
	char buff[5001];
	int count[26] = { 0, };

	while (fgets(buff, 5001, stdin) != NULL)
	{
		for (int i = 0; i < strlen(buff); ++i)
		{
			if ('a' <= buff[i] && buff[i] <= 'z')
				count[buff[i] - 'a']++;
		}
	}

	int max = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (max < count[i])
			max = count[i];
	}

	for (int i = 0; i < 26; ++i)
	{
		if (count[i] == max)
			printf("%c", 'a' + i);
	}

	return 0;
}