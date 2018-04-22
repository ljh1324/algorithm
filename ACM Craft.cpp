// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int my_time[1001];
int cost[1001];
int check[1001];		// n��° �ǹ��� ���� ���Ͽ� �̸� ����� �� �ǹ� ����
bool visited[1001];		// �湮 ����

void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cost[i] = -1;
		check[i] = 0;
		visited[i] = false;
	}
}

void dfs(int curBuilding)
{
	// �̰� �Ǽ��ð��� max���� ����� �ؼ��� �ȵǱ���! ���� �Ǽ��ɶ����� ������� �ǹ� ������ ���̳ʽ� ���־���� �ʿ䰡 �ְڴ�.
	// �׷��� max���� �ϴ� ����ϰ� ������� �ǹ� ������ 0�� �ɶ��� DFS�� �����ϸ� �ɰ� ����!
	if (check[curBuilding] != 0)
		return;

	// �湮 ����
	visited[curBuilding] = true;

	int myCost = cost[curBuilding];
	int calCost = 0;
	for (int i = 0; i < graph[curBuilding].size(); ++i)
	{
		
		calCost = myCost + my_time[graph[curBuilding][i]];
		if (cost[graph[curBuilding][i]] < calCost)
			cost[graph[curBuilding][i]] = calCost;
		check[graph[curBuilding][i]]--;
		dfs(graph[curBuilding][i]);
	}
}

int main()
{
	int numOfCase;
	int constructN, ruleN;
	int x, y;
	int wantBuilding;
	
	cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i)
	{
		cin >> constructN >> ruleN;
		graph = vector<vector<int>>(constructN, vector<int>());
		init(constructN);

		for (int j = 0; j < constructN; ++j)
		{
			cin >> my_time[j];	// �Ǽ��ð� �Է�
		}

		for (int j = 0; j < ruleN; ++j)
		{
			cin >> x >> y;	// x�ǹ��� ���� ��� y�ǹ��� ���� �� ����
			x--;
			y--;
			graph[x].push_back(y);	// �׷��� ����
			check[y]++;				// y �ǹ��� ���� ������ ���� �Ǽ��ؾ��� �ǹ� ������ �����ش�
		}

		cin >> wantBuilding;
		for (int j = 0; j < constructN; ++j)
		{
			if (check[j] == 0 && !visited[j])
			{	// ���� ����� �� �ǹ��� ���� ���.
				cost[j] = my_time[j];
				dfs(j);
			}
		}

		wantBuilding--;
		cout << cost[wantBuilding] << endl;
	}

	return 0;
}