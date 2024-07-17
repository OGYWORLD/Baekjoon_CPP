#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isVisited[101][101];
vector<int> result;

int cnt = 0;

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

void DFS(int idxI, int idxJ, int& cnt, int m, int n);

int m, n, k;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			isVisited[i][j] = false;
		}
	}

	cin >> m >> n >> k;

	int x1, y1, x2, y2;
	int index = 0;
	while (index < k)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				isVisited[i][j] = true;
			}
		}

		index++;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isVisited[i][j])
			{
				int cnt = 0;

				DFS(i, j, cnt, m, n);

				result.push_back(cnt);
			}
		}
	}


	cout << result.size() << "\n";

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}

void DFS(int idxI, int idxJ, int& cnt, int m, int n)
{
	stack<pair<int, int>> s;
	s.push({ idxI, idxJ });

	isVisited[idxI][idxJ] = true;

	cnt++;

	while (!s.empty())
	{
		int curI = s.top().first;
		int curJ = s.top().second;

		s.pop();

		for (int t = 0; t < 4; t++)
		{
			int newI = curI + deltaX[t];
			int newJ = curJ + deltaY[t];

			if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && !isVisited[newI][newJ])
			{
				s.push({ newI, newJ });

				isVisited[newI][newJ] = true;

				cnt++;
			}
		}
	}
}
