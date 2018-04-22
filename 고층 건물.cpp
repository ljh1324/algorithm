// https://www.acmicpc.net/problem/1027
// �� Ǯ��

/*
#include <stdio.h>
#include <stack>

using namespace std;

int n;
int building_height[50];
int building_visible[50];
stack<int> stk;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", building_height + i);
	
	int num_of_building = 1;
	building_visible[0] = 0;
	stk.push(building_height[0]);
	for (int i = 1; i < n; ++i)
	{
		building_visible[i] = num_of_building;

		while (!stk.empty() && building_height[i] >= stk.top())
		{
			num_of_building--;
			stk.pop();
		}
		num_of_building++;
		stk.push(building_height[i]);
	}

	num_of_building = 1;
	stk = stack<int>();
	stk.push(building_height[n - 1]);
	int max = building_visible[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		building_visible[i] += num_of_building;
		if (max < building_visible[i])
			max = building_visible[i];

		while (!stk.empty() && building_height[i] >= stk.top())
		{
			num_of_building--;
			stk.pop();
		}
		num_of_building++;
		stk.push(building_height[i]);
	}

	printf("%d\n", max);

	return 0;
}
*/


// ���ܰ� �ʹ� ���� �� �ϴ�@@@@@@@@@@@@@@@@@@@@@@@@@@@22

/*
#include <stdio.h>

int main()
{
	int n;
	int building[50];
	int see[50];
	double height, height2;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &building[i]);
		see[i] = 0;
	}

	int max = -1;
	for (int i = 0; i < n; ++i)
	{
		double up = -0.99;
		double down = -0.99;
		int downIdx = -1;

		for (int j = i + 1; j < n; ++j)
		{
			if (up < 0.0 && building[i] > building[j])
			{
				if (building[j] > down)  // ex) 5 2 3. 5���� 2�� ���� ���¿��� ���� 3�� ���� 
				{
					down = building[j];
					downIdx = j;

					see[j]++;
					see[i]++;
					if (max < see[j])
						max = see[j];

					else if (max < see[i])
						max = see[i];
				}
				else
				{
					height = (building[i] - building[j]) / (double)(j - i);
					height2 = (building[i] - down) / (double)(downIdx - i);
					if (height < height2) // ex) 10 5 4. 10���� down�� 5�� �� 10�� 4�� �̾��� �� �ֳ� ��
					{
						see[j]++;
						see[i]++;

						if (max < see[j])
							max = see[j];

						else if (max < see[i])
							max = see[i];
					}
				}
			}
			else if (building[i] <= building[j])
			{
				height = (building[j] - building[i]) / (double)(j - i);
				if (height > up)
				{
					up = height;

					see[j]++;
					see[i]++;
					if (max < see[j])
						max = see[j];

					else if (max < see[i])
						max = see[i];
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}
*/

// �� ������ Ǫ�� �� �ᱹ Ʋ�Ƚ��ϴٰ� ������..
#include <stdio.h>

int main()
{
	int n;
	int building[50];
	int see[50];
	double height, height2;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &building[i]);
		see[i] = 0;
	}

	int max = -1;
	for (int i = 0; i < n; ++i)		// ���ʿ��� ������ ������ ����.
	{
		double up = -0.99;

		for (int j = i + 1; j < n; ++j)
		{
			if (building[i] <= building[j])
			{	// ���̰� ���ų� �� ���� ������ �ִٸ� ��ȭ���� ���.
				height = (building[j] - building[i]) / (double)(j - i);
				if (height > up)
				{
					up = height;

					see[j]++;
					see[i]++;
					if (max < see[j])
						max = see[j];

					else if (max < see[i])
						max = see[i];
				}
			}
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		double up = -0.99;

		for (int j = i - 1; j >= 0; --j)
		{
			if (building[i] < building[j])
			{   // ���̰� �� ���� ������ �ִٸ� ��ȭ���� ���. (�̹� �������� ������ ��������Ƿ�)
				height = (building[j] - building[i]) / (double)(i - j);
				if (height > up)
				{
					up = height;

					see[j]++;
					see[i]++;
					if (max < see[j])
						max = see[j];

					else if (max < see[i])
						max = see[i];
				}
			}
		}
	}
	printf("%d\n", max);

	return 0;
}