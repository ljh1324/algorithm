// https://www.acmicpc.net/problem/1152
// �� Ǯ��
// �ذ�!!!! ���� ��������

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string str;

int main()
{
	int word_n = 0;

	getline(cin, str);
	str += ' ';

	bool check = false;
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == ' ' && check)
		{
			word_n++;
			check = false;
		}
		else if (str[i] != ' ')
			check = true;

	printf("%d\n", word_n);

	return 0;
}