

#include <iostream>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void printPrime(int n) {
	for (int i = 2; i <= n; ++i)
	{
		if (isPrime(i))
		{
			cout << i << ", ";
		}
	}
	cout << endl;
}
int main()
{
	printPrime(2000);
	return 0;
}