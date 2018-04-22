// https://www.acmicpc.net/problem/10871
// ÇØ°á

#include <iostream>

using namespace std;

int main()
{
	int n, x;
	int input;

	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &input);
		if (input < x)
			printf("%d ", input);
	}
	printf("\n");

	return 0;
}