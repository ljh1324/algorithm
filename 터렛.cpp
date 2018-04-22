// https://www.acmicpc.net/problem/1002
// 예외가 많쿤요..

#include <iostream>
#include <cmath>

using namespace std;

const double DOUBLE_MIN = 2.22507e-308;

double calc_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int calc_distance2(int x1, int y1, int x2, int y2)
{
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

double calc_number_of_overap_dot(int x1, int y1, int x2, int y2, int r1, int r2)
{
	if (x1 == x2 && y1 == y2) {
		if (r1 == r2)
			return -1;
		else
			return 0;
	}

	double dist = calc_distance(x1, y1, x2, y2);
	if (dist > r1 + r2)
		return 0;

	else if ( abs(dist - r1 - r2) < DOUBLE_MIN)		// epsilon
		return 1;

	else if (dist < r1 + r2)
		return 2;


}

int calc_number_of_overap_dot2(int x1, int y1, int x2, int y2, int r1, int r2)
{
	if (x1 == x2 && y1 == y2) {
		if (r1 == r2)
			return -1;
		else
			return 0;
	}

	int dist = calc_distance2(x1, y1, x2, y2);
	if (dist > pow(r1 + r2, 2) || dist < pow(r1 - r2, 2))
		return 0;

	else if (dist == pow(r1 + r2, 2) || dist == pow(r1 - r2, 2))
		return 1;

	else
		return 2;
}

int main()
{
	int n;
	int x1, y1, x2, y2, r1, r2;
	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2  >> r2;
		// cout << calc_number_of_overap_dot(x1, y1, x2, y2, r1, r2) << endl;
		cout << calc_number_of_overap_dot2(x1, y1, x2, y2, r1, r2) << endl;
	}
	
	return 0;
}