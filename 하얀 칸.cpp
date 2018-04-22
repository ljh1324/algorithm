// https://www.acmicpc.net/problem/1100

#include <iostream>
#include <string>

using namespace std;

string matrix[8];

int main()
{
	for (int i = 0; i < 8; ++i)
		cin >> matrix[i];

	int count = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = i & 1; j < 8; j += 2)
			if (matrix[i][j] == 'F')
				count++;

	printf("%d\n", count);

	return 0;
}