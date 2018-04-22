#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// �� ���̻���� ù t���ڸ� �������� �� �׷� ��ȣ�� �־��� ��,
// �־��� �� ���̻縦 ù 2 * t ���ڸ� �������� ���Ѵ�.
// group[]�� ���̰� 0�� ���̻絵 �����Ѵ�.
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {
		// group = _group; t = _t;
	}

	bool operator () (int a, int b) {
		// ù t���ڰ� �ٸ��� �̵��� �̿��� ���Ѵ�.
		if(group[a] != group[b]) return group[a] < group[b];
		// �ƴ϶�� S[a+t..]�� S[b+t..]�� ù t���ڸ� ���Ѵ�.
		return group[a + t] < group[b + t];
	}
};

// s�� ���̻� �迭�� ����Ѵ�.
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	// group[i] = ���̻���� ù t���ڸ� �������� �������� ��,
	//           s[i..]�� ���� �׷� ��ȣ.
	// t=1�� ���� ������ �� ���� S[i..]�� ù ���ڷ� �׷� ��ȣ�� ���� �൵ ���� ȿ���� �ִ�.
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;
	// ��������� ���̻� �迭�� �� ��ȯ ��. �� �迭�� lg(n)�� �����Ѵ�.
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;
	while (t < n) {
		// group[]�� ù t���ڸ� �������� ����� �״�.
		// ù 2t���ڸ� �������� perm�� �ٽ� �����Ѵ�
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		// 2t���ڰ� n�� �Ѵ´ٸ� ���� ���ϻ� �迭 �ϼ�!
		t *= 2;
		if (t >= n) break;
		// 2t���ڸ� �������� �� �׷� ������ �����
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; ++i)
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}

void main()
{
	vector<int> suffixArray = getSuffixArray("abcde");
	for (int i = 0; i < 5; ++i)
	{
		cout << suffixArray[i] << " ";
	}
	return;
}