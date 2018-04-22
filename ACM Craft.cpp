// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int my_time[1001];
int cost[1001];
int check[1001];		// n번째 건물을 짓기 위하여 미리 지어야 할 건물 갯수
bool visited[1001];		// 방문 여부

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
	// 이게 건설시간의 max값만 계산을 해서는 안되구나! 따라서 건설될때마다 지어야할 건물 갯수를 마이너스 해주어야할 필요가 있겠다.
	// 그래서 max값은 일단 계산하고 지어야할 건물 갯수가 0이 될때만 DFS를 실행하면 될것 같네!
	if (check[curBuilding] != 0)
		return;

	// 방문 도장
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
			cin >> my_time[j];	// 건설시간 입력
		}

		for (int j = 0; j < ruleN; ++j)
		{
			cin >> x >> y;	// x건물을 지을 경우 y건물을 지을 수 있음
			x--;
			y--;
			graph[x].push_back(y);	// 그래프 연결
			check[y]++;				// y 건물을 짓기 이전에 먼저 건설해야할 건물 갯수를 더해준다
		}

		cin >> wantBuilding;
		for (int j = 0; j < constructN; ++j)
		{
			if (check[j] == 0 && !visited[j])
			{	// 먼저 지어야 할 건물이 없을 경우.
				cost[j] = my_time[j];
				dfs(j);
			}
		}

		wantBuilding--;
		cout << cost[wantBuilding] << endl;
	}

	return 0;
}