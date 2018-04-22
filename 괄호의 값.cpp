// https://www.acmicpc.net/problem/2504
// ±ò²ûÇÏ°Ô ÇØ°á ^o^

#include <stack>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	char str[30];
	bool flag = true;
	stack<int> stk;

	scanf("%s", &str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '(')
			stk.push(-1);
		else if (str[i] == '[')
			stk.push(-2);
		else if (str[i] == ')')
		{
			int sum = 0;
			while (!stk.empty() && stk.top() >= 0)
			{
				sum += stk.top();
				stk.pop();
			}
			if (stk.empty() || stk.top() != -1)
			{
				flag = false;
				break;
			}
			stk.pop();
			if (sum == 0)
				stk.push(2);
			else
				stk.push(sum * 2);
		}
		else if (str[i] == ']')
		{
			int sum = 0;
			while (!stk.empty() && stk.top() >= 0)
			{
				sum += stk.top();
				stk.pop();
			}
			if (stk.empty() || stk.top() != -2)
			{
				flag = false;
				break;
			}
			stk.pop();
			if (sum == 0)
				stk.push(3);
			else
				stk.push(sum * 3);
		}
	}

	if (flag)
	{
		bool check = true;
		int sum = 0;
		while (!stk.empty())
		{
			if (stk.top() < 0)
			{
				check = false;
				break;
			}
			sum += stk.top();
			stk.pop();
		}
		if (check)
			printf("%d\n", sum);
		else
			printf("%d\n", 0);
	}
	else
		printf("%d\n", 0);

	return 0;
}