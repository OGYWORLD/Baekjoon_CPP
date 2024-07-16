#include <iostream>
#include <set>

using namespace std;

int table[5][5];
set<string> result;

void DFS(int idxI, int idxJ, string s, int depth);

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> table[i][j];
		}
	}

	string s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			DFS(i, j, s, 0);
		}
	}

	cout << result.size();

	return 0;
}

void DFS(int idxI, int idxJ, string s, int depth)
{
	if (depth == 5)
	{
		s += table[idxI][idxJ];

		result.insert(s);

		s.pop_back();

		return;
	}

	s += table[idxI][idxJ];

	for (int k = 0; k < 4; k++)
	{
		if (idxI + deltaX[k] < 5 && idxI + deltaX[k] > -1 && idxJ + deltaY[k] < 5 && idxJ + deltaY[k] > -1)
		{
			DFS(idxI + deltaX[k], idxJ + deltaY[k], s, depth + 1);
		}
	}

	s.pop_back();
}
