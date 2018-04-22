// https://www.acmicpc.net/problem/1017
// 시간 초과

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prime[2001] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999 };
int prime_size;

bool is_prime[2001] = { 0, };
bool print_check[2001] = { false, };
int arr[50];
int pair[50];
bool check[50];
int isExist;

int pair_list[2001];
int pair_list_size = 0;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void my_qsort(int* arr, int start, int end)
{
	if (end - start <= 0) return;

	srand(time(NULL));

	int rand_idx = rand() % (end - start + 1) + start;
	int pivot = arr[rand_idx];

	swap(arr[start], arr[rand_idx]);

	int i = start;
	int j = end + 1;

	do
	{
		do {
			i++;
		} while (i <= end && arr[i] < pivot);
		do {
			j--;
		} while (j >= start + 1 && arr[j] > pivot);

		if (i >= j) break;
		swap(arr[i], arr[j]);
	} while (1);

	swap(arr[start], arr[j]);
	my_qsort(arr, start, j - 1);
	my_qsort(arr, j + 1, end);
}

void init(int n) {
	isExist = false;

	int size = sizeof(prime) / sizeof(int);
	for (int i = 0; i < size; ++i)
	{
		is_prime[prime[i]] = true;
	}
	
	for (int i = 0; i < n; ++i)
	{
		check[i] = false;
	}
}

void recursive_pair(int size) {
	if (print_check[pair[0]])	// 이미 출력되있을 경우 return으로 가지치기
		return;

	int first = -1;
	for (int i = 0; i < size; ++i)
	{
		if (!check[i])
		{
			first = i;
			break;
		}
	}
	
	if (first == -1)	// 모든 짝이 지어 졌을 경우
	{
		isExist = true;
		if (!print_check[pair[0]])
		{
			// printf("%d ", pair[0]);		// 첫번째 수와 지어진 짝 출력
			pair_list[pair_list_size++] = pair[0];
			print_check[pair[0]] = true;
		}
		return;
	}

	for (int i = first + 1; i < size; ++i)
	{
		if (!check[i] && is_prime[arr[first] + arr[i]])
		{
			check[first] = check[i] = true;
			pair[first] = arr[i];
			if (first == 0)
				print_check[pair[0]] = false;
			recursive_pair(size);
			check[first] = check[i] = false;
		}
	}
}

int main()
{
	int n;
	int max = -1;
	scanf("%d", &n);
	

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}
	
	init(n);
	recursive_pair(n);
	if (!isExist)
		printf("%d\n", -1);
	else
	{
		my_qsort(pair_list, 0, pair_list_size - 1);
		for (int i = 0; i < pair_list_size; ++i)
			printf("%d ", pair_list[i]);
		printf("\n");
	}
	return 0;
}