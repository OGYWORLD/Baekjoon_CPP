#include <iostream>

#define MAX_NUM	999999999

using namespace std;

int ar[101][101];
int n;

void ArrayInit();
void GetArray();
void FindRoad();
void PrintArray();


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	ArrayInit();
	GetArray();
	FindRoad();
	PrintArray();

	return 0;
}

void ArrayInit()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ar[i][j] = MAX_NUM;
		}
	}
}

void GetArray()
{
	int entity;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> entity;

			if (entity == 1)
			{
				ar[i][j] = 0;
			}
		}
	}
}

void FindRoad()
{
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (ar[s][e] > ar[s][k] + ar[k][e])
				{
					ar[s][e] = ar[s][k] + ar[k][e];
				}
			}
		}
	}
}

void PrintArray()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (ar[i][j] != MAX_NUM)
			{
				cout << "1 ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}
