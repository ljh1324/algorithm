// https://www.acmicpc.net/problem/1013

#include <stdio.h>
#include <string>

using namespace std;

bool automata(string s) {
	int state = 0;
	int idx = 0;
	int changeCheck;
	string next;

	while (true) {
		changeCheck = false;
		switch (state) {
		case 0:
			if (idx + 3 <= s.length())
			{
				next = s.substr(idx, 3);
				if (next == "100")
				{
					state = 1;
					idx += 3;
					changeCheck = true;
					break;
				}
			}
			if (idx + 2 <= s.length())
			{
				next = s.substr(idx, 2);
				if (next == "01")
				{
					state = 0;
					idx += 2;
					changeCheck = true;
					break;
				}
			}
			break;

		case 1:
			if (idx + 1 <= s.length())
			{
				next = s.substr(idx, 1);
				idx += 1;
				changeCheck = true;

				if (next == "0")
				{
					state = 1;
				}
				else
				{
					state = 2;
				}
			}
			break;

		case 2:
			if (idx + 3 <= s.length())
			{
				next = s.substr(idx, 3);
				if (next == "100")
				{
					state = 1;
					idx += 3;
					changeCheck = true;
					break;
				}
			}
			if (idx + 2 <= s.length())
			{
				next = s.substr(idx, 2);
				if (next == "01")
				{
					state = 0;
					idx += 2;
					changeCheck = true;
					break;
				}
			}
			if (idx + 1 <= s.length())
			{
				next = s.substr(idx, 1);
				if (next == "1")
				{
					state = 2;
					idx += 1;
					changeCheck = true;
					break;
				}
			}
			break;
		} // switch
		if (!changeCheck)
			return false;

		if (idx == s.length())
			return state == 0 || state == 2;
	}
}

int main()
{
	int tc;
	string s;
	char c_str[201];

	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%s", c_str);
		s = c_str;

		if (automata(s))
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");
	}
	return 0;
}