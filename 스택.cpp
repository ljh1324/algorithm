// https://www.acmicpc.net/problem/10828
// ÇØ°á~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	stack<int> stk;
	char instruction[128];
	int value;
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", instruction);
		if (strcmp("push", instruction) == 0)
		{
			scanf("%d", &value);
			stk.push(value);
		}
		else if (strcmp("top", instruction) == 0)
		{
			if (stk.empty())
				printf("%d\n", -1);
			else
				printf("%d\n", stk.top());
		}
		else if (strcmp("size", instruction) == 0)
		{
			printf("%d\n", stk.size());
		}
		else if (strcmp("empty", instruction) == 0)
		{
			printf("%d\n", stk.empty());
		}
		else  // pop
		{
			if (stk.empty())
				printf("%d\n", -1);
			else
			{
				int t = stk.top();
				stk.pop();
				printf("%d\n", t);
			}
		}
	}
	return 0;
}