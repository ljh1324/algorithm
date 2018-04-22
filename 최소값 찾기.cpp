// https://www.acmicpc.net/problem/11003
// 시간초과....

/*
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

struct node {
	int value;
	node* prev;
	node* next;
};

int main()
{
	queue<int> q;
	node nums[5000001];
	int value;

	nums[0].prev = 0;
	nums[0].next = 0;
	
	int n, l;
	
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; ++i)
	{
		if (q.size() >= l)
		{	// // l을 넘을 경우 빼준다.
			int top = q.front();
			q.pop();
			node* del = &nums[top];
			del->prev->next = del->next;
			if (del->next)
				del->next->prev = del->prev;
		}
		q.push(i);

		scanf("%d", &value);
		node* start = &nums[0];

		nums[i].value = value;

		if (start->next == 0) // 오름차순으로 연결리스트에 삽입합니다.
		{	// 더미일 경우
			nums[i].prev = start;
			nums[i].next = 0;
			start->next = &nums[i];
		}
		else
		{
			start = start->next;
			while (start->next != 0 && start->value < value)
			{   // start->value >= value일때 까지 반복
				start = start->next;
			}
			
			if (start->value > value)
			{	// start->value > value일 경우 value를 start 전에 넣는다.
				nums[i].prev = start->prev;
				nums[i].next = start;
				start->prev->next = &nums[i];
				start->prev = &nums[i];
			}
			else
			{
				nums[i].prev = start;
				nums[i].next = start->next;
				if (start->next)
					start->next->prev = &nums[i];
				start->next = &nums[i];
			}
		}

		cout << nums[0].next->value << " ";
	}

	return 0;
}
*/

// 해결~~~~~~~~~~~~~
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct node {
	int value, index;

	node(int value, int index) : value(value), index(index) {}
	node() {}
};

class heap {
private:
	vector<node> my_heap;

public:
	heap() {
		my_heap.push_back(node());
	}

	void push(node n) {
		my_heap.push_back(n);
		int last = my_heap.size() - 1;
		while (last != 1 && my_heap[last / 2].value > n.value) {
			swap(my_heap[last / 2], my_heap[last]);
			last /= 2;
		}
	}

	bool isEmpty() {
		return my_heap.size() == 1;
	}

	node top() {
		if (my_heap.size() != 1)
			return my_heap[1];
	}

	void pop() {
		swap(my_heap[1], my_heap[my_heap.size() - 1]);

		my_heap.pop_back();
		
		/*
		int idx = 1;
		int child = idx * 2;
		while (child < my_heap.size() && my_heap[child].value < my_heap[idx].value)
		{
			if (child + 1 < my_heap.size() && my_heap[child].value > my_heap[child + 1].value)
				child += 1;
			swap(my_heap[child], my_heap[idx]);
			idx = child;
			child = idx * 2;
		}
		*/

		int idx = 1;
		while(1)
		{
			int child = idx * 2;
			if (child >= my_heap.size())
				break;

			if (child + 1 < my_heap.size() && my_heap[child].value > my_heap[child + 1].value)
				child += 1;

			if (my_heap[child].value >= my_heap[idx].value)
				break;

			swap(my_heap[child], my_heap[idx]);
			idx = child;
		}
	}

private:
	void swap(node& a, node& b) {
		node temp = a;
		a = b;
		b = temp;
	}
};

int main()
{
	heap h;
	node n;

	int s, l;
	int value;

	scanf("%d %d", &s, &l);
	for (int i = 0; i < s; ++i)
	{
		scanf("%d", &value);
		h.push(node(value, i));

		do {
			n = h.top();
			if (n.index < i - l + 1)
				h.pop();
			else
				break;
		} while (1);

		printf("%d ", n.value);
	}

	return 0;
}