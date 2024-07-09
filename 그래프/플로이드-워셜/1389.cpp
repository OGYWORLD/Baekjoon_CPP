#include <iostream>

#define MAX_NUM	101
#define INF	999999999

using namespace std;

int user[MAX_NUM][MAX_NUM];
int n, m;

void UserInit();
void Floyd();
void FindMin();

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	UserInit();

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		if (user[a][b] != 1)
		{
			user[a][b] = 1;
			user[b][a] = 1;
		}
	}

	Floyd();
	FindMin();

	return 0;
}

void UserInit()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		for (int j = 0; j < MAX_NUM; j++)
		{
			if (i != j)
			{
				user[i][j] = INF;
			}
			else
			{
				user[i][j] = 0;
			}
		}
	}
}

void Floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (user[s][e] > user[s][k] + user[k][e])
				{
					user[s][e] = user[s][k] + user[k][e];
				}
			}
		}
	}
}

void FindMin()
{
	int min = INF;
	int sum = 0;
	int minPerson = INF;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += user[i][j];
		}

		if (min > sum)
		{
			min = sum;
			minPerson = i;
		}
		else if (min == sum)
		{
			if (minPerson > i)
			{
				minPerson = i;
			}
		}
		sum = 0;
	}

	cout << minPerson;
}