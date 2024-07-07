#include <iostream>

#define TOTAL_CITY	101
#define MAX_NUM		999999999

using namespace std;

int city[TOTAL_CITY][TOTAL_CITY];

void ArrayInit();
void Floyd(int n);
void PrintArray(int n);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ArrayInit();

	int n, m;
	cin >> n >> m;
	
	int s, e, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> cost;

		if (city[s][e] > cost)
		{
			city[s][e] = cost;
		}
	}

	Floyd(n);
	PrintArray(n);

	return 0;
}

void ArrayInit()
{
	for (int i = 1; i < TOTAL_CITY; i++)
	{
		for (int j = 1; j < TOTAL_CITY; j++)
		{
			if (i == j)
			{
				city[i][j] = 0;
			}
			else
			{
				city[i][j] = MAX_NUM;
			}
		}
	}
}

void Floyd(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int srt = 1; srt <= n; srt++)
		{
			for (int end = 1; end <= n; end++)
			{
				if (city[srt][end] > city[srt][k] + city[k][end])
				{
					city[srt][end] = city[srt][k] + city[k][end];
				}
			}
		}
	}
}

void PrintArray(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == MAX_NUM)
			{
				cout << "0 ";
			}
			else
			{
				cout << city[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
