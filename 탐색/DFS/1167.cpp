#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static vector<vector<pair<int, int>>> AdjTree(100001);
static int IsVisited[100001];
static int Max = -1;
static int MaxNode = 0;

void DFS(int node, int cost, int TotalCost)
{
	IsVisited[node] = true;
	TotalCost += cost;

	if (Max < TotalCost)
	{
		Max = TotalCost;
		MaxNode = node;
	}

	int PopNode;
	int PopEdgeCost = 0;
	pair<int, int> PopPair;

	for (int i = 0; i < AdjTree[node].size(); i++)
	{
		if (!IsVisited[AdjTree[node][i].first])
		{
			DFS(AdjTree[node][i].first, AdjTree[node][i].second, TotalCost);
		}
	}

	IsVisited[node] = false;
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V;
	cin >> V;

	vector<pair<int, int>> GetTree;

	int GetMainNode;
	int GetSubNode;
	int GetCost;
	for (int i = 0; i < V; i++)
	{
		cin >> GetMainNode;
		while (1)
		{
			cin >> GetSubNode;
			if (GetSubNode == -1)
			{
				break;
			}
			cin >> GetCost;

			GetTree.push_back(pair<int, int>(GetSubNode, GetCost));
		}
		AdjTree[GetMainNode] = GetTree;
		GetTree.clear();
	}

	DFS(1, 0, 0);
	DFS(MaxNode, 0, 0);

	cout << Max << "\n";

	return 0;
}