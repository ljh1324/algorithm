// https://www.acmicpc.net/problem/4752
// 예외가 너무 많다@@@@@@@@@@@@@@@@@@@@@@@@

#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int b, e;
	char str[201];
	string tag;
	string copy;
	string word;

	do
	{
		stack<string> stk;
		scanf("%d %d", &b, &e);
		if (b == -1 && e == -1)
			break;

		scanf("%s", str);
		int len = strlen(str);
		int idx = 0;
		int flag = false;

		for (int i = 0; i < e; ++i)
		{
			if (str[i] == '<')
			{
				flag = true;
			}
			else if (str[i] == '>')
			{
				flag = false;
				if (stk.empty())
					stk.push(tag);
				else if ('/' + stk.top() == tag)
				{
					if (b <= i)
					{ 
						copy = copy + '<' + stk.top() + '>' + word + '<' + tag + '>';
						word = "";
					}
					stk.pop();
				}
				else
				{
					stk.push(tag);
				}
			}
			else if (b <= i)
			{
				word += str[i];
			}
		}
		printf("%s\n", copy);

	} while (1);

	return 0;
}