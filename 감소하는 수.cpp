// https://www.acmicpc.net/problem/1038

// 시간 초과

/*
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	int idx = 0;
	int desc = 0;
	while (idx != n)
	{
		i++;
		printf("%d\n", idx);
		int temp = i;
		int max = -1;
		int radix;
		bool flag = true;
		while (temp != 0)
		{
			radix = temp % 10;
			if (radix > max)
				max = radix;
			else
			{
				flag = false;
				break;
			}
			temp /= 10;
		}
		if (flag)
		{
			idx++;
			desc = i;
		}
	}

	printf("%d\n", desc);
	return 0;
}
*/

/*
#include <stdio.h>

// int dp[1000000];


bool isDecrease(int n, int before)
{
	if (dp[n] != -1)			// n이 11일때 true가 반환됨... 왜냐하면 11에서 10을 빼고나서 1을 보는데, dp[1]은 이미 true이기 때문에 true를 반환한다.
		return dp[n];

	int temp = n;
	int first = 0;
	int radix = 1;
	while (temp != 0)
	{
		first = temp % 10;
		temp /= 10;
		radix *= 10;
	}
	radix /= 10;

	if (first < before)
	{
		dp[n] = isDecrease(n - first * radix, first);
	}
	else
		dp[n] = false;

	return dp[n];
} 
*/

/*
bool isDecrease(int n)
{
	int temp = n;
	
	int first = 0;
	int second = 0;
	int radix = 1;

	first = temp % 10;
	temp /= 10;
	
	while (temp != 0)
	{
		second = first;
		first = temp % 10;
		temp /= 10;
		radix *= 10;
	}

	// 동적 프로그래밍이라지만 사실상 위의 while문에서 비교를 하면 쓸모가 없다.
	// 따라서 이것도 시간 초과가 될 듯
	if (first > second)
	{
		dp[n] = dp[n - first * radix];
	}
	else
		dp[n] = false;

	if (dp[n])
		printf("%d\n", n);

	return dp[n];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[0] = true;

	int n;
	int cnt = 1;
	int number = 1;
	scanf("%d", &n);

	while (cnt != n)
	{
		if (isDecrease(number))
			cnt++;
		number++;
	}
	printf("%d\n", number);

	return 0;
}
*/

#include <stdio.h>
// 꺄야야야야 해결했다@@@@@

bool isDecrease(unsigned long long n, int& second, int& radix)
{
	unsigned long long temp = n;

	int first = 0;
	radix = 1;
	second = 0;

	first = temp % 10;
	temp /= 10;

	while (temp != 0)
	{
		second = first;
		first = temp % 10;
		if (first <= second)
		{
			// radix /= 10;
			// if (radix == 0)
			//	radix = 1;
			return false;
		}
		temp /= 10;
		radix *= 10;
	}
//	if (flag)
//		printf("%d\n", n);
//	printf("%llu\n", n);
	return true;
}

int main()
{
	int n;
	int cnt = 0;
	unsigned long long number = 1;
	int second, radix;
	scanf("%d", &n);
	if (n == 0)
	{
		printf("%d\n", 0);
		return 0;
	}

	// printf("%llu\n", 9876543210);

	while (number <= (unsigned long long)9876543210)
	{
		if (isDecrease(number, second, radix))
		{
			cnt++;
			if (cnt == n)
				break;
			number++;
		}
		else
		{
			number += (10 - second) * radix;		// first보다 second가 크므로 second의 자리수는 건너뛰어도 된다.
		}

		if (cnt > n)
			break;
		
	}
	if (cnt != n)
		printf("%d\n", -1);
	else
		printf("%llu\n", number);		// unsigned long long을 출력하기 위해서는 %d를 사용하면 안되고 %llu를 사용해야한다.

	return 0;
}