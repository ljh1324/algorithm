// https://www.acmicpc.net/problem/8958
// ÇØ°á

#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		int len = s.length();
		int point = 1;
		int sum = 0;
		for (int j = 0; j < len; ++j)
		{
			if (s[j] == 'X')
				point = 1;
			else
				sum += point++;
		}
		cout << sum << endl;
	}

	return 0;
}