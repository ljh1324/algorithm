// https://www.acmicpc.net/problem/9012

#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char str[52];

	scanf("%d", &n);

	int parenN;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", str);
		parenN = 0;

		for (int j = 0; j < strlen(str); ++j)
		{
			if (str[j] == '(')
				parenN++;
			else
				parenN--;

			if (parenN < 0)
				break;
		}

		if (parenN == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}