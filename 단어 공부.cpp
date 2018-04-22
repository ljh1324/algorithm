// https://www.acmicpc.net/problem/1157
// ÇØ°á

#include <stdio.h>
#include <string.h>

int main()
{
	int alphabet[26];
	char str[1000001];
	int maxIdx;

	scanf("%s", str);
	for (int i = 0; i < 26; ++i)
		alphabet[i] = 0;

	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			alphabet[str[i] - 'A']++;
		else
			alphabet[str[i] - 'a']++;
	}

	maxIdx = 0;
	for (int i = 1; i < 26; ++i)
		if (alphabet[i] > alphabet[maxIdx])
			maxIdx = i;


	for (int i = 0; i < 26; ++i)
		if (alphabet[i] == alphabet[maxIdx] && i != maxIdx)
		{
			printf("?\n");
			return 0;
		}

	printf("%c\n", maxIdx + 'A');

	return 0;
}