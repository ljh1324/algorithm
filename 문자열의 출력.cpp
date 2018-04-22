#include <iostream>
using namespace std;

/*
int main()
{
	char str[] = "Hello World!";
	int arrLength = sizeof(str);

	for (int i = 0; i < arrLength; ++i)
			cout << str + i << endl;
}
*/

/*
int main()
{
char str[2000] = { 0, };

for (int i = 0; i < 3; ++i) {
cout << i + 1 << "번째 문자열을 입력하세요 : ";
cin >> str + strlen(str);
}

cout << "str : " << str << endl;
}
*/
int my_strcmp(char* str1, char* str2)
{
	int str1Length = strlen(str1);
	int str2Length = strlen(str2);

	for (int i = 0; i < str1Length && i < str2Length; ++i)
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;

	if (str1Length == str2Length)
		return 0;
	else if (str1Length < str2Length)
		return 1;
	else
		return -1;
}

int my_strcmp2(char* str1, char *str2)
{
	while (1) {
		if (*str1 != *str2)
			return *str1 - *str2;
		if (*str1 == 0)
			return 0;
		str1++;
		str2++;
	}
}

void my_strcpy(char* dest, char* src) {
	for (int i = 0; i <= strlen(src); ++i)
		dest[i] = src[i];
}

void my_strcpy2(char* dest, char* src) {
	while(1) {
		*dest = *src;
		if (*src == 0)
			break;
		dest++; src++;
	}
}

void my_strcat(char* dest, char* src) {
	int start = strlen(dest);
	for (int i = 0; i <= strlen(src); ++i)
		dest[start + i] = src[i];
}

void my_strcat2(char* dest, char* src) {
	int start = strlen(dest);
	while (1) {
		*(dest + start) = *src;
		if (*src == 0)
			break;
		dest++;
		src++;
	}
}

int my_strlen(char* str)
{
	int length = 0;
	while (str[length])
		length++;

	return length;
}

int my_strlen2(char* str)
{
	int length = 0;
	while (!(*str))
	{
		length++;
		str++;
	}

	return length;
}
int main()
{
	char str1[] = "ABC";
	char str2[] = "BCD";
	char str3[] = "ABA";
	char str4[] = "ABC";

	cout << strcmp(str1, str2) << endl;
	cout << strcmp(str1, str3) << endl;
	cout << strcmp(str1, str4) << endl;

	cout << my_strcmp2(str1, str2) << endl;
	cout << my_strcmp2(str1, str3) << endl;
	cout << my_strcmp2(str1, str4) << endl;

	char str5[] = "ABCDE";
	char str6[11];

	my_strcpy2(str6, str5);
	cout << str6 << endl;
	my_strcat2(str6, str5);
	cout << str6 << endl;

	int length = my_strlen2(str6);
	cout << length << endl;
	return 0;
}