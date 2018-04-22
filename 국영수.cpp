// https://www.acmicpc.net/problem/10825

#include <stdio.h>
#include <string>

using namespace std;


struct student {
	string name;
	int korean;
	int english;
	int math;
};

student stu[100000];

int compare(const student& a, const student& b)
{
	if (a.korean < b.korean)
		return 1;
	else if (a.korean > b.korean)
		return -1;

	if (a.english > b.english)
		return 1;
	else if (a.english < b.english)
		return -1;

	if (a.math < b.math)
		return 1;
	else if (a.math > b.math)
		return -1;

	if (a.name > b.name)
		return 1;
	else if (a.name < b.name)
		return -1;

	return 0;
}

void swap(student& a, student& b)
{
	student temp = a;
	a = b;
	b = temp;
}

void qsort(student *arr, int l, int r)
{
	int left = l;
	int right = r;
	student pivot = arr[(l + r) / 2];

	while (left <= right)
	{
		while (compare(arr[left], pivot) == -1)
			left++;
		while (compare(arr[right], pivot) == 1)
			right--;

		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	if (l < right) qsort(arr, l, right);
	if (r > left) qsort(arr, left, r);
}

int main()
{
	int n;
	char str[11];
	

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d %d %d", str, &stu[i].korean, &stu[i].english, &stu[i].math);
		stu[i].name = str;
	}

	qsort(stu, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", stu[i].name.c_str());
	}

	return 0;
}