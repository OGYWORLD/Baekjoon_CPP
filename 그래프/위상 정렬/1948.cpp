#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<vector<pair<int, int>>> Adj;
vector<vector<pair<int, int>>> AdjReverse;
vector<int> TotalTime;
vector<int> Connect;
vector<bool> IsVisited;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Adj.resize(N + 1);
	AdjReverse.resize(N + 1);
	Connect.resize(N + 1, 0);
	TotalTime.resize(N + 1, 0);
	IsVisited.resize(N + 1, false);

	int N1, N2, T;
	for (int i = 0; i < M; i++)
	{
		cin >> N1 >> N2 >> T;

		Adj[N1].push_back(pair<int, int>(N2, T));
		AdjReverse[N2].push_back(pair<int, int>(N1, T));

		Connect[N2]++;
	}

	int Srt, End;
	cin >> Srt >> End;

	queue<int> Q;
	Q.push(Srt);

	while (Q.size() != 0)
	{
		int PopNode = Q.front();
		Q.pop();
		
		for (int i = 0; i < Adj[PopNode].size(); i++)
		{
			Connect[Adj[PopNode][i].first]--;

			if (Connect[Adj[PopNode][i].first] == 0)
			{
				Q.push(Adj[PopNode][i].first);
			}

			if (TotalTime[Adj[PopNode][i].first] < TotalTime[PopNode] + Adj[PopNode][i].second)
			{
				TotalTime[Adj[PopNode][i].first] = TotalTime[PopNode] + Adj[PopNode][i].second;
			}
		}

	}

	Q.push(End);
	int Cnt = 0;
	IsVisited[End] = true;
	while (Q.size() != 0)
	{
		int PopNode = Q.front();
		Q.pop();

		for (int i = 0; i < AdjReverse[PopNode].size(); i++)
		{
			if (TotalTime[PopNode] == TotalTime[AdjReverse[PopNode][i].first] + AdjReverse[PopNode][i].second)
			{
				Cnt++;
				if (!IsVisited[AdjReverse[PopNode][i].first])
				{
					Q.push(AdjReverse[PopNode][i].first);
					IsVisited[AdjReverse[PopNode][i].first] = true;
				}
			}
		}
	}

	cout << TotalTime[End] << "\n" << Cnt;

	return 0;
}
