// https://www.acmicpc.net/problem/1213

#include <stdio.h>

struct Point {
	int x, y;
};

void swap(Point& a, Point& b)
{
	Point temp = a;
	a = b;
	b = temp;
}

void qsort(Point* arr, int l, int r)
{
	int left = l;
	int right = r;
	Point pivot = arr[(l + r) / 2];

	while (left <= right)
	{
		while (arr[left].y < pivot.y || (arr[left].y == pivot.y && arr[left].x < pivot.x))
			left++;
		while (arr[right].y > pivot.y || (arr[right].y == pivot.y && arr[right].x > pivot.x))
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
	Point arr[100000];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	return 0;
}