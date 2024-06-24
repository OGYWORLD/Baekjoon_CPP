#include <iostream>

#define TOTAL_NUM	101
#define DELTA		4

using namespace std;

int stage[TOTAL_NUM][TOTAL_NUM];
bool isVisited[TOTAL_NUM][TOTAL_NUM];

int n, m;

// idx 0: Blue, idx 1: White
int power[] = { 0, 0 };
int powerIdx = 0;

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

void DFS(int i, int j);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// Init
	for (int i = 0; i < TOTAL_NUM; i++)
	{
		for (int j = 0; j < TOTAL_NUM; j++)
		{
			stage[i][j] = 0;
			isVisited[i][j] = false;
		}
	}

	cin >> n >> m;

	char line[101];
	for (int i = 0; i < m; i++)
	{
		cin >> line;
		for (int j = 0; j < n; j++)
		{
			stage[i][j] = line[j];
		}
	}

	int result[] = {0, 0};

	// DFS
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isVisited[i][j])
			{
				if ((char)stage[i][j] == 'B')
				{
					powerIdx = 0;
				}
				else
				{
					powerIdx = 1;
				}

				DFS(i, j);

				result[powerIdx] += power[powerIdx] * power[powerIdx];

				power[powerIdx] = 0;
			}
		}
	}

	cout << result[1] << " " << result[0];

	return 0;
}

void DFS(int i, int j)
{
	isVisited[i][j] = true;
	power[powerIdx]++;

	char curChar = stage[i][j];

	for (int k = 0; k < DELTA; k++)
	{
		if ((i + deltaX[k] > -1 && i + deltaX[k] < m && j + deltaY[k] > -1 && j + deltaY[k] < n) && (curChar == stage[i + deltaX[k]][j + deltaY[k]]))
		{
			if (!isVisited[i + deltaX[k]][j + deltaY[k]])
			{
				DFS(i + deltaX[k], j + deltaY[k]);
			}
		}
	}
}