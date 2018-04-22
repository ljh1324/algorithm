#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

vector<int> getPartialMatchNaive(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	for (int begin = 1; begin < m; ++begin)
	{
		for (int i = 0; i + begin < m; ++i)
		{
			if (N[begin + i] != N[i]) break;
			pi[begin + i] = max(pi[begin + i], i + 1);
		}
	}

	return pi;
}

int main()
{
	string s = "aaaa";
	vector<int> pi = getPartialMatchNaive(s);
	for (int i = 0; i < pi.size(); ++i)
		cout << pi[i] << " ";
	return 0;
}