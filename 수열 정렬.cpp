// https://www.acmicpc.net/problem/1015

#include <stdio.h>

using namespace std;

int main()
{
	int size;
	int value, max;
	int location[1001] = { 0, };
	int arr[51];
	scanf("%d", &size);

	max = -1;
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &value);
		location[value]++;
		arr[i] = value;
		if (value > max)
			max = value;
	}

	int temp = 0;
	int before = 0;
	for (int i = 1; i <= max; ++i)
	{
		temp = location[i];
		location[i] = before + location[i - 1];
		before = temp;
	}

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", location[arr[i]]++);
	}
}