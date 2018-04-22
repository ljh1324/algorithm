// https://www.acmicpc.net/problem/1057
// Ç®¾ú´ç

#include <stdio.h>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = a;
}

int main()
{
	int participant;
	int player1, player2;
	int round;

	scanf("%d %d %d", &participant, &player1, &player2);


	round = 1;
	while (1)
	{
		player1 += player1 & 1;
		player2 += player2 & 1;
		player1 /= 2;
		player2 /= 2;
		if (player1 == player2)
			break;
		round++;
	}

	printf("%d\n", round);

	return 0;
}