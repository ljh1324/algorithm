// ���α׷��� ��ȸ���� ���� �˰��� �����ذ����� - ���� ������ �����ϱ�
#include <iostream>
#include <string>

using namespace std;

int overlap(string a, string b)
{
	for (int i = 0; i < a.size(); ++i)
	{
		int a_idx = i;
		int b_idx = 0;

		bool flag = true;
		while (a_idx < a.size() && b_idx < b.size())
			if (a[a_idx++] != b[b_idx++])
			{
				flag = false;
				break;
			}

		if (flag)
			return b_idx;	// ��ģ ��ŭ ��ȯ
	}

	return 0;
}

int main()
{
	cout << overlap("abc", "ab") << endl;
	cout << overlap("abc", "bcd") << endl;
	cout << overlap("abcd", "e") << endl;
	return 0;
}