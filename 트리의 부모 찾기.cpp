// https://www.acmicpc.net/problem/11725
// 왜 40%에서 틀렸습니다 라고 나올까..
// 해결ㅋㅋ..

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> arr[100001];
bool visited[100001];

// int my_parent[100000]; 참.... 어이없는 이유로!!!!!!!!!!! 틀렸다!!!!!!!!!!
int my_parent[100001];

void findParent(int parent)
{
	int size = arr[parent].size();
	for (int i = 0; i < size; ++i)
	{
		if (!visited[arr[parent][i]])
		{
			visited[arr[parent][i]] = 1;
			my_parent[arr[parent][i]] = parent;
			findParent(arr[parent][i]);
		}
	}
}

int main()
{
	memset(visited, 0, sizeof(visited));

	int n;
	int node1, node2;

	scanf("%d", &n);
	if (n == 1)
	{ 
		return 0;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d", &node1, &node2);
		arr[node1].push_back(node2);
		arr[node2].push_back(node1);
	}

	visited[1] = true;
	findParent(1);
	for (int i = 2; i <= n; ++i)
	{
		printf("%d\n", my_parent[i]);
	}
	return 0;
}