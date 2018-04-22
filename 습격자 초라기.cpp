#include <iostream>
#include <string>

using namespace std;

int onetagon[2][10000];
int conquer[2][10000];

int n, w;
int min;

int dx[] = { 1, 0, -1 };
int dy[] = { 0, 1, 0 }; 

bool isAllConquer() {
	for (int i = 0; i < n; ++i) {
		if (!conquer[0][i] || !conquer[1][i])
			return false;
	}
	return true;
}

void calcNeedForce(int x, int y, int force) {
	
	if (isAllConquer()) {
		if (force < min)
			min = force;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{

	}
}

int main()
{
	int numOfCase;
	
	cin >> numOfCase;
	for (int i = 0; i < numOfCase; ++i)
	{
		cin >> n;

		for (int j = 0; j < n; ++j)
			cin >> onetagon[0][i];
		for (int j = 0; j < n; ++j)
			cin >> onetagon[1][i];
		for (int j = 0; j < n; ++j) {
			conquer[0][j] = false;
			conquer[1][j] = false;
		}

		min = n * 2;
	}

	return 0;
}