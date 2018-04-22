// https://www.acmicpc.net/problem/1181

#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

void swap(char* a, char* b)
{
	char temp[51];
	int a_len = strlen(a);
	int b_len = strlen(b);

	for (int i = 0; i < a_len; ++i)
		temp[i] = a[i];
	
	for (int i = 0; i < b_len; ++i)
		a[i] = b[i];
	a[b_len] = '\0';

	for (int i = 0; i < a_len; ++i)
		b[i] = temp[i];
	b[a_len] = '\0';
}

void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

void qsort(string *arr, int l, int r)
{
	int left = l;
	int right = r;
	string pivot = arr[(l + r) / 2];

	while (left <= right)
	{
		while (arr[left].length() < pivot.length() || (arr[left].length() == pivot.length() && arr[left] < pivot))
			left++;
		while (arr[right].length() > pivot.length() || (arr[right].length() == pivot.length() && arr[right] > pivot))
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

void qsort(char arr[][51], int l, int r)
{
	int left = l;
	int right = r;
	char* pivot = arr[(l + r) / 2];
	int len = strlen(pivot);

	while (left <= right)
	{

		while (strlen(arr[left]) < len || (strlen(arr[left]) == len && strcmp(arr[left], pivot) < 0))
			left++;
		while (strlen(arr[right]) > len || (strlen(arr[right]) == len && strcmp(arr[right], pivot) > 0))
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
	char str[51];
	string str_arr[20000];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		// scanf("%s", str[i]);
		scanf("%s", str);
		str_arr[i] = string(str);
	}

	// qsort(str, 0, n - 1);
	qsort(str_arr, 0, n - 1);

	// printf("%s\n", str[0]);
	printf("%s\n", str_arr[0].c_str());
	for (int i = 1; i < n; ++i)
		// if (strcmp(str[i - 1], str[i]))
		// printf("%s\n", str[i]);
		if (str_arr[i - 1] != str_arr[i])
			printf("%s\n", str_arr[i].c_str());

	return 0;
}