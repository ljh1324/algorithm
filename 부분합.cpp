#include <iostream>
#include <vector>

using namespace std;

vector<int> partialSum(const vector<int>& a)
{
	vector<int> psum(a.size());

	psum[0] = a[0];
	for (int i = 1; i < a.size(); ++i)
		psum[i] = psum[i - 1] + a[i];
	return psum;
}

vector<int> squarePartialSum(const vector<int>& a)
{
	vector<int> sqpsum(a.size());

	sqpsum[0] = a[0] * a[0];
	for (int i = 1; i < a.size(); ++i)
		sqpsum[i] = sqpsum[i - 1] + a[i] * a[i];
	return sqpsum;
}

vector<vector<int>> partialSum2D(const vector<vector<int>> a)
{
	vector<vector<int>> psum2D(a.size(), vector<int>(a[0].size()));
	psum2D[0][0] = a[0][0];
	int psum;

	for (int i = 0; i < a.size(); ++i)
	{
		psum = 0;
		for (int j = 0; j < a[0].size(); ++j)
		{
			if (i == 0 && j == 0)
				continue;

			psum += a[i][j];
			psum2D[i][j] += psum;
			if (i != 0)
				psum2D[i][j] += psum2D[i - 1][j];
			
		}
	}
	return psum2D;
}

// 어떤 2차원 배열 A[][]의 부분합 psum[][]이 주어질 때,
// A[y1, x1]과 A[y2, y2]를 양 끝으로 갖는 부분 배열의 합을 반환한다.
int gridSum(const vector<vector<int>>& psum, int y1, int x1, int y2, int x2) {
	int ret = psum[y2][x2];
	if (y1 > 0) ret -= psum[y1 - 1][x2];
	if (x1 > 0) ret -= psum[y2][x1 - 1];
	if (y1 > 0 && x1 > 0) ret += psum[y1 - 1][x1 - 1];
	return ret;
}

int main()
{
	vector<vector<int>> a(3, vector<int>(3));
	for (int i = 0; i < 3; ++i)
	{
		a[0][i] = i;
		a[1][i] = i;
		a[2][i] = i;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[0].size(); ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}

	vector<vector<int>> psum = partialSum2D(a);
	for (int i = 0; i < psum.size(); ++i)
	{
		for (int j = 0; j < psum.size(); ++j)
			cout << psum[i][j] << " ";
		cout << endl;
	}
	cout << gridSum(psum, 1, 1, 2, 2) << endl;
	return 0;
}