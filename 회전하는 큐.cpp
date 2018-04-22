// https://www.acmicpc.net/problem/1021
// «ÿ∞·≈©

#include <deque>
#include <iostream>

using namespace std;

int main()
{
	deque<int> dq;
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		dq.push_back(i + 1);

	int pop;
	int move = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> pop;
		int loc = 0;
		while (dq[loc] != pop) loc++;

		int middle = dq.size() / 2;
		if (loc <= middle)
		{
			for (int i = 0; i < loc; ++i)
			{ 
				int top = dq.front();
				dq.pop_front();
				dq.push_back(top);
				move++;
			}
			dq.pop_front();
		}
		else
		{
			for (int i = loc; i < dq.size(); ++i)
			{
				int back = dq.back();
				dq.pop_back();
				dq.push_front(back);;
				move++;
			}
			dq.pop_front();
		}
	}

	cout << move << endl;

	return 0;
}