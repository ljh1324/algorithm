// https://www.acmicpc.net/problem/1251
// 문제해결!

#include <string>
#include <iostream>

using namespace std;

string word;
string min_word = "";

void brute_force(int start, int partition, int idx[2])
{
	if (partition == 2)
	{
		string front = word.substr(0, idx[0] + 1);
		string middle = word.substr(idx[0] + 1, idx[1] - idx[0]);
		string tail = word.substr(idx[1] + 1);

		string r_front;
		for (int i = 0; i < front.length(); ++i)
			r_front = front[i] + r_front;

		
		string r_middle;
		for (int i = 0; i < middle.length(); ++i)
			r_middle = middle[i] + r_middle;

		string r_tail;
		for (int i = 0; i < tail.length(); ++i)
			r_tail = tail[i] + r_tail;

		string merge = r_front + r_middle + r_tail;
		if (min_word == "" || min_word > merge)
			min_word = merge;

		return;
	}

	int len = word.length();
	for (int i = start; i < len - 1; ++i)
	{
		idx[partition] = i;
		brute_force(i + 1, partition + 1, idx);
	}
}

int main()
{
	cin >> word;

	int idx[2];
	brute_force(0, 0, idx);

	cout << min_word << endl;
	return 0;
}