#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> Adj;
vector<bool> IsVisited;
vector<int> MinCost;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Adj.resize(N + 1);
	IsVisited.resize(N + 1, false);
	MinCost.resize(N + 1, 999999999);

	int A, B, Cost;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> Cost;

		Adj[A].push_back(pair<int, int>(B, Cost));
	}

	int Srt, End;
	cin >> Srt >> End;

	priority_queue<pair<int, int>> Q;
	Q.push(pair<int, int>(0, Srt));
	MinCost[Srt] = 0;


	while (!Q.empty())
	{
		int PopNode = Q.top().second;
		int PopCost = -Q.top().first;
		Q.pop();

		if (IsVisited[PopNode])
		{
			continue;
		}

		IsVisited[PopNode] = true;

		for (int i = 0; i < Adj[PopNode].size(); i++)
		{
			if (MinCost[Adj[PopNode][i].first] > MinCost[PopNode] + Adj[PopNode][i].second)
			{
				MinCost[Adj[PopNode][i].first] = MinCost[PopNode] + Adj[PopNode][i].second;
				Q.push(pair<int, int>(-MinCost[Adj[PopNode][i].first], Adj[PopNode][i].first));
			}
		}
	}

	cout << MinCost[End];

	return 0;
}
