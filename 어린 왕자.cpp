// https://www.acmicpc.net/problem/1004

#include <iostream>
#include <cmath>

using namespace std;

typedef struct Point {
	int x, y;
};

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main()
{
	int numOfCase, circleN;
	int x1, y1, x2, y2;
	int cx, cy, r;
	int cnt;
	double dist_with_start, dist_with_end;

	cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i)
	{
		
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> circleN;
		cnt = 0;
		for (int j = 0; j < circleN; ++j)
		{
			cin >> cx >> cy >> r;

			dist_with_start = distance(x1, y1, cx, cy);
			dist_with_end = distance(x2, y2, cx, cy);

			if (dist_with_start <= r && dist_with_end <= r)
			{
				// 시작점과 도착점이 하나의 원 안에 있을 때
			}
			else if (dist_with_start <= r || dist_with_end <= r)
			{
				// 시작점이나 도착점이 하나의 원 안에 있을 때
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}