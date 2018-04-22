// https://www.acmicpc.net/problem/2470
// 해결

#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int arr[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	sort(arr, arr + n);
	
	int left = 0;
	int right = n - 1;
	int minSum = 2000000001;
	int minLeft, minRight;
	int sum;

	// -10000 1 2 3 4 와 같은 경우 계속 right가 줄어든다.
	/*
	while (left < right) {
		sum = arr[left] + arr[right];
		if (abs(sum) < minSum)
		{
			minSum = sum;
			minLeft = arr[left];
			minRight = arr[right];
			if (sum == 0)
				break;
		}
		
		if (sum > 0)
			right--;
		else
			left++;
	}
	*/

	while (1) {
		sum = arr[left] + arr[right];
		if (abs(sum) < minSum)
		{
			minSum = abs(sum);
			minLeft = arr[left];
			minRight = arr[right];
			if (sum == 0)
				break;
		}

		if (right - left >= 2)
		{
			if (abs(arr[left + 1] + arr[right]) < abs(arr[left] + arr[right - 1]))
				left++;
			else
				right--;
		}
		else
			break;
	}

	printf("%d %d", minLeft, minRight);

	return 0;
}