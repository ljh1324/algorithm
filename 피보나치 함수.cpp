// https://www.acmicpc.net/problem/1003

#include <iostream>

using namespace std;

typedef struct Count {
	int zeroCount;
	int oneCount;
};

Count dp[41];

Count fibonacci(int n) {
	if (dp[n].zeroCount != -1)
		return dp[n];


	Count c;
	if (n == 0) {
		c.zeroCount = 1;
		c.oneCount = 0;
	}
	else if (n == 1) {
		c.zeroCount = 0;
		c.oneCount = 1;
	}
	else {
		Count fibo1 = fibonacci(n - 1);
		Count fibo2 = fibonacci(n - 2);

		c.zeroCount = 0;
		c.oneCount = 0;

		c.zeroCount += fibo1.zeroCount;
		c.zeroCount += fibo2.zeroCount;

		c.oneCount += fibo1.oneCount;
		c.oneCount += fibo2.oneCount;
	}
	dp[n] = c;

	return c;
}

void init(int n) {
	for (int i = 0; i <= n; ++i)
		dp[i].zeroCount = -1;
}

int main()
{
	int numOfCase;
	int fiboN;

	cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i)
	{
		cin >> fiboN;
		init(fiboN);
		Count count = fibonacci(fiboN);
		cout << count.zeroCount << " " << count.oneCount << endl;
	}
	return 0;
}
