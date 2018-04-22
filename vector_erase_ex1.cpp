/*

제너릭 unique 알고리즘은 입력 시퀀스에서 모든 연속 중복 원소들을 모두 제거한다.
시퀀스 상에서 자신의 왼쪽에 위치한 원소와 값이 동일하면, 그 원소는 중복 원소에
해당한다. 따라서, 원소들로 구성된 그룹이 있다면 그 그룹의 맨 앞의 원소를 제외한
나머지 원소는 unique 알고리즘을 통해 제거된다.
unique 는 컨테이너의 사이즈를 변경하지 않는다. 대신, 연속 중복 원소가 아닌 것들
을 구간의 왼편에 몰아 넣고, "unique"한 원소들이 끝나는 위치를 가리키는 반복자를
리턴한다.

단, 중복되어 있다고 해서 무조건 제거되는 것이 아니라 반드시 연속적으로 중복되어
있는 경우에만 삭제된다.

template <class ForwardIterator>
ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
	if (first==last) return last;

	ForwardIterator result = first;	// result를 first로 초기화
	while (++first != last)			// first가 다음 위치를 가르키고 나서 last가 아닐 동안 반복
	{
		if (!(*result == *first))  // 만약 result가 가르키는 값과 first가 가르키는 값이 다를 경우
			*(++result)=*first;	   // result의 다음 위치에 first가 가르키는 값을 저장
	}
	return ++result;
}

시간 복잡도는 선형적이다.

참고 : http://laitdei.tistory.com/entry/STL-unique
참고2 : http://www.cplusplus.com/reference/algorithm/unique/

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
	
	// 원소가 2인 반복자를 찾는다.
	vector<int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); ++iter)
		if (*iter == 2)		
			break;

	// 원소가 2인 반복자를 지운다.
	arr.erase(iter);

	cout << "arr1 : ";
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;

	// 원소가 2인 반복자를 찾는다.
	for (iter = arr2.begin(); iter != arr2.end(); ++iter)
		if (*iter == 2)
			break;

	// 원소가 2인 반복자 부터 마지막 원소까지 원소를 지운다.
	arr2.erase(iter, arr2.end());

	cout << "arr2 : ";
	for (int i = 0; i < arr2.size(); ++i)
		cout << arr2[i] << " ";
	cout << endl;

	// "unique"한 원소들을 왼편으로 몰아 넣은 후 삭제되지 않은 마지막 원소의 iterator반환
	iter = unique(arr3.begin(), arr3.end());

	cout << "arr3 : ";
	for (int i = 0; i < arr3.size(); ++i)	
		cout << arr3[i] << " ";
	cout << endl;

	//  "unique"한 원소들이 끝나는 위치를 가리키는 반복자 부터 마지막 원소까지 삭제
	arr4.erase(unique(arr4.begin(), arr4.end()), arr4.end());

	cout << "arr4 : ";
	for (int i = 0; i < arr4.size(); ++i)
		cout << arr4[i] << " ";
	cout << endl;
	return 0;
}