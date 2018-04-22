// https://www.acmicpc.net/problem/2455
// ÇØ°á

#include <stdio.h>

int main()
{
	int in, out;
	int people = 0;
	int max = -1;

	while (1)
	{
		scanf("%d %d", &out, &in);
		people -= out;
		people += in;

		if (people > max)
			max = people;

		if (in == 0)
			break;
	}

	printf("%d\n", max);

	return 0;
}