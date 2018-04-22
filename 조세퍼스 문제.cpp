// https://www.acmicpc.net/problem/1158

#include <stdio.h>

using namespace std;

struct Data {
	int value;
	Data* next;
};

int main()
{
	Data dataPool[10000];

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		dataPool[i].value = i + 1;
		dataPool[i].next = &dataPool[i + 1];
	}
	dataPool[n - 1].next = &dataPool[0];

	int count = 0;
	Data* ptr = &dataPool[n - 1];
	printf("<");
	while (1)
	{
		for (int i = 0; i < m - 1; ++i)
			ptr = ptr->next;
		if (ptr->next == ptr)
		{
			printf("%d>", ptr->value);
			break;
		}
		else
		{
			printf("%d, ", ptr->next->value);
			ptr->next = ptr->next->next;			// next°ª »èÁ¦
		}
	}

	return 0;
}