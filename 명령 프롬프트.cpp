// https://www.acmicpc.net/problem/1032

#include <stdio.h>
#include <string.h>

int main()
{
	int strN;
	char my_str[50][51];

	scanf("%d", &strN);
	for (int i = 0; i < strN; ++i)
	{
		scanf("%s", my_str[i]);
	}

	int length = strlen(my_str[0]);
		for (int j = 0; j < length; ++j)
			for (int i = 1; i < strN; ++i)
			{
				if (my_str[0][j] != my_str[i][j])
				{
					my_str[0][j] = '*';
					break;
				}
			}

	for (int i = 0; i < length; ++i)
	{
		if (my_str[0][i] == '*')
			printf("%c", '?');
		else
			printf("%c", my_str[0][i]);
	}
	printf("\n");

	return 0;
}