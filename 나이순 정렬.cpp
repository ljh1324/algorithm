// https://www.acmicpc.net/problem/10814

#include <stdio.h>
#include <string>

using namespace std;


struct person {
	string name;
	int age;
	int join;
};

person stu[100000];

int compare(const person& a, const person& b)
{
	if (a.age > b.age)
		return 1;
	else if (a.age < b.age)
		return -1;

	if (a.join > b.join)
		return 1;
	else if (a.join < b.join)
		return -1;

	return 0;
}

void swap(person& a, person& b)
{
	person temp = a;
	a = b;
	b = temp;
}

void qsort(person *arr, int l, int r)
{
	int left = l;
	int right = r;
	person pivot = arr[(l + r) / 2];

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
	char str[101];


	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %s", &stu[i].age, str);
		stu[i].name = str;
		stu[i].join = i;
	}

	qsort(stu, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		printf("%d %s\n", stu[i].age, stu[i].name.c_str());
	}

	return 0;
}