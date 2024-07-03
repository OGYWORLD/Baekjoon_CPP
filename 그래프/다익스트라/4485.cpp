#include <iostream>
#include <queue>

using namespace std;

int adj[126][126];
int isVisited[126][126];
int minCost[126][126];

void Init();

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int deltaX[] = { -1, 1, 0, 0 };
	int deltaY[] = { 0, 0, -1, 1 };

	// Init
	Init();

	// -cost, (i, j)
	priority_queue<pair<int, pair<int, int>>> targetNode;

	int n;
	int index = 1;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> adj[i][j];
			}
		}

		// First Search Node Cost Init
		minCost[0][0] = adj[0][0];

		// Search Min Cost
		targetNode.push(pair<int, pair<int, int>>(minCost[0][0], pair<int, int>(0, 0)));
		while (targetNode.size() != 0)
		{
			int cost = -targetNode.top().first;
			int indexI = targetNode.top().second.first;
			int indexJ = targetNode.top().second.second;

			targetNode.pop();

			if (isVisited[indexI][indexJ])
			{
				continue;
			}

			isVisited[indexI][indexJ] = true;

			for (int i = 0; i < 4; i++)
			{
				int targetI = deltaX[i] + indexI;
				int targetJ = deltaY[i] + indexJ;

				// Valid Check
				if (!isVisited[targetI][targetJ] && targetI < n && targetI > -1 && targetJ < n && targetJ > -1)
				{
					// Min Search
					if (minCost[targetI][targetJ] > minCost[indexI][indexJ] + adj[targetI][targetJ])
					{
						minCost[targetI][targetJ] = minCost[indexI][indexJ] + adj[targetI][targetJ];
						targetNode.push(pair<int, pair<int, int>>(-minCost[targetI][targetJ], pair<int, int>(targetI, targetJ)));
					}
				}
			}
		}

		cout << "Problem " << index << ": " << minCost[n-1][n-1] << "\n";

		// Priority Queue Clear
		while (targetNode.size() != 0)
		{
			targetNode.pop();
		}

		Init();

		index++;
	}


	return 0;
}

void Init()
{
	for (int i = 0; i < 126; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			adj[i][j] = 0;
			isVisited[i][j] = false;
			minCost[i][j] = 999999999;
		}
	}
}
