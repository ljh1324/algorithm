/*

���ʸ� unique �˰����� �Է� ���������� ��� ���� �ߺ� ���ҵ��� ��� �����Ѵ�.
������ �󿡼� �ڽ��� ���ʿ� ��ġ�� ���ҿ� ���� �����ϸ�, �� ���Ҵ� �ߺ� ���ҿ�
�ش��Ѵ�. ����, ���ҵ�� ������ �׷��� �ִٸ� �� �׷��� �� ���� ���Ҹ� ������
������ ���Ҵ� unique �˰����� ���� ���ŵȴ�.
unique �� �����̳��� ����� �������� �ʴ´�. ���, ���� �ߺ� ���Ұ� �ƴ� �͵�
�� ������ ���� ���� �ְ�, "unique"�� ���ҵ��� ������ ��ġ�� ����Ű�� �ݺ��ڸ�
�����Ѵ�.

��, �ߺ��Ǿ� �ִٰ� �ؼ� ������ ���ŵǴ� ���� �ƴ϶� �ݵ�� ���������� �ߺ��Ǿ�
�ִ� ��쿡�� �����ȴ�.

template <class ForwardIterator>
ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
	if (first==last) return last;

	ForwardIterator result = first;	// result�� first�� �ʱ�ȭ
	while (++first != last)			// first�� ���� ��ġ�� ����Ű�� ���� last�� �ƴ� ���� �ݺ�
	{
		if (!(*result == *first))  // ���� result�� ����Ű�� ���� first�� ����Ű�� ���� �ٸ� ���
			*(++result)=*first;	   // result�� ���� ��ġ�� first�� ����Ű�� ���� ����
	}
	return ++result;
}

�ð� ���⵵�� �������̴�.

���� : http://laitdei.tistory.com/entry/STL-unique
����2 : http://www.cplusplus.com/reference/algorithm/unique/

*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	vector<int> arr2 = arr;
	vector<int> arr3 = arr;
	vector<int> arr4 = arr;

	cout << "arr1 : ";
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
	
	// ���Ұ� 2�� �ݺ��ڸ� ã�´�.
	vector<int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); ++iter)
		if (*iter == 2)		
			break;

	// ���Ұ� 2�� �ݺ��ڸ� �����.
	arr.erase(iter);

	cout << "arr1 : ";
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;

	// ���Ұ� 2�� �ݺ��ڸ� ã�´�.
	for (iter = arr2.begin(); iter != arr2.end(); ++iter)
		if (*iter == 2)
			break;

	// ���Ұ� 2�� �ݺ��� ���� ������ ���ұ��� ���Ҹ� �����.
	arr2.erase(iter, arr2.end());

	cout << "arr2 : ";
	for (int i = 0; i < arr2.size(); ++i)
		cout << arr2[i] << " ";
	cout << endl;

	// "unique"�� ���ҵ��� �������� ���� ���� �� �������� ���� ������ ������ iterator��ȯ
	iter = unique(arr3.begin(), arr3.end());

	cout << "arr3 : ";
	for (int i = 0; i < arr3.size(); ++i)	
		cout << arr3[i] << " ";
	cout << endl;

	//  "unique"�� ���ҵ��� ������ ��ġ�� ����Ű�� �ݺ��� ���� ������ ���ұ��� ����
	arr4.erase(unique(arr4.begin(), arr4.end()), arr4.end());

	cout << "arr4 : ";
	for (int i = 0; i < arr4.size(); ++i)
		cout << arr4[i] << " ";
	cout << endl;
	return 0;
}