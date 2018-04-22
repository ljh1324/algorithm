// https://www.acmicpc.net/problem/1966

#include <queue>
#include <iostream>


using namespace std;

int main()
{
	int numOfCase;
	int paperN, wantIdx;
	int value, result;
	int count;

	cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i)
	{
		cin >> paperN >> wantIdx;
		queue<pair<int, int>> my_page;
		priority_queue<int> pq;

		for (int j = 0; j < paperN; ++j)
		{
			cin >> value;
			my_page.push(pair<int, int>(value, j));
			pq.push(value);
		}

		count = 0;
		while (1) {
			result = pq.top();

			if (my_page.front().first == result)
			{
				count++;
				pq.pop();

				if (my_page.front().second == wantIdx)
					break;
				my_page.pop();
			}

			result = pq.top();
			while (my_page.front().first != result)
			{
				pair<int, int> value = my_page.front();
				my_page.pop();
				my_page.push(value);
			}
		}

		cout << count << endl;
	}
	return 0;
}