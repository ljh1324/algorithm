// https://www.acmicpc.net/problem/1167

// ���� ����� ���̰� second_max���� �� ��� ������ �߻��� �� �ִ�.....
/*
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

struct Edge {
	int vertex, dist;
	Edge(int vertex, int dist) : vertex(vertex), dist(dist) {}
};

vector<Edge> arr[100001];
bool visited[100001];


int first_max = 0;
int second_max = 0;

void calcDist(int parent, int depth)
{


	int size = arr[parent].size();
	bool flag = true;
	for (int i = 0; i < size; ++i)
	{
		if (!visited[arr[parent][i].vertex])
		{
			flag = false;
			visited[arr[parent][i].vertex] = 1;
			calcDist(arr[parent][i].vertex, depth + arr[parent][i].dist);
		}
	}

	if (flag)
	{
		if (first_max <= depth)
		{
			second_max = first_max;
			first_max = depth;
		}
	}
}

int main()
{
	memset(visited, 0, sizeof(visited));

	int n;
	int node, dist;
	int parent;

	scanf("%d", &n);
	if (n == 1)
	{
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &parent);
		while(1)
		{
			scanf("%d", &node);
			if (node == -1)
				break;
			scanf("%d", &dist);
			arr[parent].push_back(Edge(node, dist));
		}
	}

	visited[1] = true;
	calcDist(1, 0);
	printf("%d\n", first_max + second_max);

	return 0;
}

*/

// �� �´� �̰� ����� ���̷� �����Ѵ�...
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

struct Edge {
	int vertex, dist;
	Edge(int vertex, int dist) : vertex(vertex), dist(dist) {}
};

vector<Edge> arr[100001];
bool visited[100001];


int max = -1;

int calcDist(int parent, int depth)
{
	int size = arr[parent].size();
	int dist;
	int first = 0, second;

	bool flag = true;
	for (int i = 0; i < size; ++i)
	{
		if (!visited[arr[parent][i].vertex])
		{
			flag = false;
			visited[arr[parent][i].vertex] = 1;
			dist = calcDist(arr[parent][i].vertex, depth + arr[parent][i].dist);
			if (dist > first)
			{
				second = first;
				first = dist;
				if (first + second > max)
					max = first + second;
			}
		}
	}

	if (flag)
	{
		return depth;
	}
	return first;		// ���� ����� ���̸� ��ȯ
}

int main()
{
	memset(visited, 0, sizeof(visited));

	int n;
	int node, dist;
	int parent;

	scanf("%d", &n);
	if (n == 1)
	{
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &parent);
		while (1)
		{
			scanf("%d", &node);
			if (node == -1)
				break;
			scanf("%d", &dist);
			arr[parent].push_back(Edge(node, dist));
		}
	}

	visited[1] = true;
	calcDist(1, 0);
	printf("%d\n", max);

	return 0;
}