// https://www.acmicpc.net/problem/7568
// 흠흠.... 뭔가 간단한 방법을 생각해야 해결할 수 있을 것 같다...
// 문제를 잘 읽어 봐야겠다.. 해결ㅜㅜ

#include <stdio.h>
//#include <algorithm>

using namespace std;

int weight[50], height[50];

//int comparator(const void* a, const void* b)
//{
//	if (weight[*(int*)a] < weight[*(int*)b] && height[*(int*)a] < height[*(int*)b])
//		return 1;
//	else if (weight[*(int*)a] > weight[*(int*)b] && height[*(int*)a] > height[*(int*)b])
//		return -1;
//	else
//		return 0;
//}

int main()
{
	int n;
	int rank[50];
	int idx[50];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &weight[i], &height[i]);
		idx[i] = i;
	}

	// qsort(idx, n, sizeof(int), comparator);

	//for (int i = 0; i < n; ++i)
	//{
	//	printf("%d %d\n", weight[idx[i]], height[idx[i]]);
	//}

	for (int i = 0; i < n; ++i)
	{
		int r = 1;
		for (int j = 0; j < n; ++j)
		{
			if (j == i)
				continue;

			if (weight[i] < weight[j] && height[i] < height[j])
				r++;
		}
		rank[i] = r;
	}

	//rank[idx[0]] = 1;
	//int cnt = 1;
	//for (int i = 1; i < n; ++i)
	//{
	//	/*		
	//	if ( (weight[idx[i - 1]] > weight[idx[i]] && height[idx[i - 1]] > height[idx[i]]) || 
	//		(weight[idx[i - 1]] >= weight[idx[i]] && height[idx[i - 1]] > height[idx[i]]) ||
	//		(weight[idx[i - 1]] > weight[idx[i]] && height[idx[i - 1]] >= height[idx[i]])) 
	//	*/
	//	if ((weight[idx[i - 1]] > weight[idx[i]] && height[idx[i - 1]] > height[idx[i]]) )
	//	{
	//		rank[idx[i]] = rank[idx[i - 1]] + cnt;
	//		cnt = 1;
	//		// begin = idx[i];
	//	}
	//	else
	//	{
	//		rank[idx[i]] = rank[idx[i - 1]];
	//		cnt++;
	//	}
	//}

	for (int i = 0; i < n; ++i)
		printf("%d ", rank[i]);
	return 0;
}


