// https://www.acmicpc.net/problem/2920
// ÇØ°á

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int arr[8];
	for (int i = 0; i < 8; ++i)
	{
		scanf("%d", arr + i);
	}

	int delta = arr[0] - arr[1];
	int flag = false;

	for (int i = 2; i < 8; ++i)
	{
		if (arr[i - 1] - arr[i] != delta)
		{
			flag = true;
			break;
		}
	}

	if (flag)
		printf("mixed\n");
	else if (delta == -1)
		printf("ascending\n");
	else
		printf("descending\n");

	return 0;
}