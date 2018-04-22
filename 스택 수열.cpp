// https://www.acmicpc.net/problem/1874
// 한번에 해결 ^^7
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> stk;
	string push_pop = "";

	int arr[100000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int next = 1;
	int idx = 0;
	while (next <= n)
	{
		if (stk.empty() || stk.top() != arr[idx])
		{
			stk.push(next++);
			push_pop += '+';
		}
		while (!stk.empty() && stk.top() == arr[idx])
		{
			stk.pop();
			idx++;
			push_pop += '-';
		}
	}

	if (!stk.empty())
		printf("NO\n");
	else
	{
		int len = push_pop.length();
		for (int i = 0; i < len; ++i)
		{
			printf("%c\n", push_pop[i]);
		}
	}
	return 0;
}