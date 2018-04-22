// https://www.acmicpc.net/problem/7662

#include <queue>
#include <stdio.h>
#include <functional>

using namespace std;

int main()
{
	int tc;
	int operandN, value;
	char order;
	bool check[1000000] = { false, };

	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i) {
		scanf("%d", &operandN);

		priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int, int>> > max_heap;
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > min_heap;
		for (int i = 0; i < operandN; ++i) {
			
			scanf(" %c %d", &order, &value);
			if (order == 'I')
			{
				max_heap.push(pair<int, int>(value, i));
				min_heap.push(pair<int, int>(value, i));
				check[i] = true;
			}
			else if (order == 'D')
			{
				if (value < 0)
				{
					while (!min_heap.empty() && check[min_heap.top().second] == false)
						min_heap.pop();
					
					if (!min_heap.empty())
					{
						check[min_heap.top().second] = false;
						min_heap.pop();
					}
				}

				if (value > 0)
				{
					while (!max_heap.empty() && check[max_heap.top().second] == false)
						max_heap.pop();

					if (!max_heap.empty())
					{
						check[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
			}	// end else
		}	// end for operand 

		while (!max_heap.empty() && check[max_heap.top().second] == false)
			max_heap.pop();
		while (!min_heap.empty() && check[min_heap.top().second] == false)
			min_heap.pop();

		if (max_heap.empty() || min_heap.empty())
			printf("EMPTY\n");
		else
			printf("%d %d\n", max_heap.top().first, min_heap.top().first);

	} // end for tc
	return 0;
}