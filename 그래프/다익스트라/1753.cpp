#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> Adj;
vector<int> MinLength;
vector<int> IsVisited;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V, E, SrtNode;
	cin >> V >> E >> SrtNode;

	Adj.resize(V + 1);
	MinLength.resize(V + 1, 9999999);
	IsVisited.resize(V + 1, false);

	MinLength[SrtNode] = 0;

	int V1, V2, W;
	for (int i = 0; i < E; i++)
	{
		cin >> V1 >> V2 >> W;
		Adj[V1].push_back(pair<int, int>(V2, W));
	}

	priority_queue<pair<int, int>> Q;
	Q.push(pair<int,int>(0, SrtNode));

	while (!Q.empty())
	{
		int PopNode = Q.top().second;
		int PopNodeLength = -Q.top().first;
		Q.pop();

		if (IsVisited[PopNode])
		{
			continue;
		}

		IsVisited[PopNode] = true;

		for (int i = 0; i < Adj[PopNode].size(); i++)
		{
			if (MinLength[Adj[PopNode][i].first] > MinLength[PopNode] + Adj[PopNode][i].second)
			{
				MinLength[Adj[PopNode][i].first] = MinLength[PopNode] + Adj[PopNode][i].second;
				Q.push(pair<int, int>(-MinLength[Adj[PopNode][i].first], Adj[PopNode][i].first));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (MinLength[i] == 9999999)
		{
			cout << "INF\n";
		}
		else
		{
			cout << MinLength[i] << "\n";
		}
	}

	return 0;
}
