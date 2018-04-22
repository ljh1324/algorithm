// https://www.acmicpc.net/problem/1051

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string matrix[50];
int row, col;
int max_length;

int main()
{
	cin >> row >> col;
	
	for (int r = 0; r < row; ++r)
		cin >> matrix[r];

	max_length = row;
	if (max_length > col)
		max_length = col;
	max_length -= 1;

	int start_size = 0;
	int max_side = -1;

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
		{
			char val = matrix[r][c];

			for (int s = max_length; s >= start_size; --s)
			{
				if (r + s < row && c + s < col && matrix[r + s][c] == val && matrix[r][c + s] == val && matrix[r + s][c + s] == val)
				{
					if (s > max_side)
					{
						max_side = s;
						start_size = max_side + 1;
						break;
					}
				}
			}
			if (max_side == max_length)
				goto OUT;
		}

OUT:
	printf("%d\n", (max_side + 1) * (max_side + 1));

	return 0;
}