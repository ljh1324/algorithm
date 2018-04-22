#include <iostream>

using namespace std;

// mask에 속한 원소들의 개수를 반환한다.
int getSize(int mask)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		count += (mask & 1);
		mask = mask >> 1;
	}
	return count;
}

int getSum(int mask)
{
	int sum = 0;
	int add;
	for (int i = 0; i < 32; ++i)
	{
		sum += i * (mask & 1);
		mask = mask >> 1;
	}

	return sum;
}

int main()
{
	cout << getSize(3) << endl;
	cout << getSize(2) << endl;

	cout << getSum(3) << endl;
	cout << getSum(15) << endl;
	return 0;
}