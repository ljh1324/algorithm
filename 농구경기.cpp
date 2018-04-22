// https://www.acmicpc.net/problem/1159
// ÇØ°á

#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int n;
	int alphabet[26] = { 0, };
	char name[31];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", name);
		alphabet[name[0] - 'a']++;
	}

	bool flag = false;
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] >= 5) {
			printf("%c", i + 'a');
			flag = true;
		}
	}
	if (!flag)
		printf("PREDAJA");
	printf("\n");

	return 0;
}