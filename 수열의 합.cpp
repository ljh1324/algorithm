// https://www.acmicpc.net/problem/1024

#include <stdio.h>
#include <deque>
using namespace std;

deque<int> q;
bool flag;

int main()
{
	int n, l;
	int idx;
	int sum = 0;
	
	scanf("%d %d", &n, &l);
	idx = (n / l) + l + 1;

	for (int i = idx; i >= 0; --i)
	{
		sum += i;
		q.push_back(i);
		if (sum > n)
		{
			sum -= q.front();
			q.pop_front();
		}
		if (sum == n)
		{
			if (q.size() >= l)
			{
				flag = true;
				break;
			}
		}
		if (q.size() > 100)
			break;
	}

	int size = q.size();

	if (!flag || size > 100) {
		printf("%d\n", -1);
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			int value = q.back();
			q.pop_back();
			printf("%d ", value);
		}
		printf("\n");
	}

	return 0;
}