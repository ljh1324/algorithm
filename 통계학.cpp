// https://www.acmicpc.net/problem/2108
// 한번에 해결 ^^

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main()
{
	int n;
	int arr[500000];
	int max_freq = -1;

	int first, second;
	int flag;

	map<int, int> freq;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		freq[arr[i]]++;
	}

	map<int, int>::iterator iter;
	flag = false;
	for (iter = freq.begin(); iter != freq.end(); iter++) {
		if (max_freq < iter->second)
		{
			max_freq = iter->second;
			first = iter->first;
		}
		else if (max_freq == iter->second && first > iter->first)
		{
			first = iter->first;
		}
	}
	
	for (iter = freq.begin(); iter != freq.end(); iter++) {
		if (max_freq == iter->second && iter->first != first)
		{
			if (!flag || (first < second && second > iter->first))
			{
				flag = true;
				second = iter->first;
			}
		}
	}

	printf("%.f\n", sum / (double)n);
	printf("%d\n", arr[n / 2]);

	if (flag)
		printf("%d\n", second);
	else
		printf("%d\n", first);

	printf("%d\n", arr[n - 1] - arr[0]);

	return 0;
}