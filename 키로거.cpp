// https://www.acmicpc.net/problem/5397
// «ÿ∞·≈©!!!

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Data {
	char value;
	Data* prev;
	Data* next;

	Data(Data* prev, Data* next, char value) {
		this->prev = prev;
		this->next = next;
		this->value = value;
	}

	Data() {
		prev = nullptr;
		next = nullptr;
	}
};

char str[1000001];

int main()
{
	int tc;
	int size;
	int len;

	Data* cur;
	
	int idx;

	scanf("%d", &tc);
	for (int i = 0; i < tc; ++i)
	{
		scanf("%s", str);
		Data password[1000000];
		password[0] = Data();
		cur = &password[0];			// dummy
		len = strlen(str);
		idx = 0;

		for (int i = 0; i < len; ++i)
		{
			if (str[i] == '<' && cur->prev != nullptr)
				cur = cur->prev;
			else if (str[i] == '>' && cur->next != nullptr)
				cur = cur->next;
			else if (str[i] == '-' && cur != &password[0])
			{
				cur->prev->next = cur->next;
				if (cur->next != nullptr)
				{
					cur->next->prev = cur->prev;
				}
				cur = cur->prev;
			}
			else if (str[i] != '<' && str[i] != '>' && str[i] != '-')
			{
				
				password[++idx] = Data(cur, cur->next, str[i]);
				if (cur->next != nullptr)
					cur->next->prev = &password[idx];
				cur->next = &password[idx];
				cur = &password[idx];
			}
		}

		cur = &password[0];
		while (cur->next != nullptr)
		{
			cur = cur->next;
			printf("%c", cur->value);
		}
		printf("\n");
	}

	return 0;
}