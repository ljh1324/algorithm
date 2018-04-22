// https://www.acmicpc.net/problem/1076

#include <stdio.h>
#include <string.h>

char *resistance[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
char *multi[10] = { "","0","00","000","0000","00000","000000","0000000","00000000","000000000" };

int main()
{
	int val = 0;
	char input[10];

	for (int i = 0; i < 2; ++i)
	{
		scanf("%s", input);
		for (int j = 0; j < 10; ++j)
			if (!strcmp(input, resistance[j]))
			{
				val *= 10;
				val += j;
				break;
			}
	}

	scanf("%s", input);
	printf("%d", val);

	if (val != 0)
		for (int i = 0; i < 10; ++i)
			if (!strcmp(input, resistance[i]))
			{
				printf("%s", multi[i]);
			}
	printf("\n");

	return 0;
}