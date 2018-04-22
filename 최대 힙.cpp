#include <queue>
#include <stdio.h>

using namespace std;

int my_pq[100000];
int pq_size;

void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void push(int val) {
	my_pq[++pq_size] = val;
	int idx = pq_size;

	while (idx != 1 && my_pq[idx / 2] < my_pq[idx])
	{
		swap(my_pq[idx / 2], my_pq[idx]);
		idx /= 2;
	}
}

int pop() {
	int val = my_pq[1];
	swap(my_pq[pq_size], my_pq[1]);
	pq_size--;

	int startIdx = 1;
	while (true)
	{
		int childIdx = startIdx * 2;
		if (childIdx > pq_size)
			break;
		if (childIdx + 1 <= pq_size && my_pq[childIdx] < my_pq[childIdx + 1])
			childIdx++;

		if (my_pq[startIdx] < my_pq[childIdx])
		{
			swap(my_pq[startIdx], my_pq[childIdx]);
			startIdx = childIdx;
		}
		else
			break;
	}
	
	return val;
}

bool isEmpty() {
	return pq_size == 0;
}

int main()
{
	int n;
	int val;
	// priority_queue<int> pq;
	pq_size = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &val);
		if (val == 0)
		{
			if (isEmpty())
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", pop());
			}
			/*
			if (pq.empty())
				printf("%d\n", 0);
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			} */
		}
		else
			push(val);
			// pq.push(val);
	}

	return 0;
}