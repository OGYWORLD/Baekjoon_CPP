#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<vector<pair<int, int>>> Adj;
vector<priority_queue<int>> KthMin;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	Adj.resize(N + 1);
	KthMin.resize(N + 1);

	int A, B, C;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		Adj[A].push_back(pair<int, int>(B, C));
	}

	KthMin[1].push(0);

	typedef pair<int, int> edge;
	priority_queue<edge, vector<edge>, greater<edge>> Q;
	Q.push(pair<int, int>(0, 1));

	while (!Q.empty())
	{
		int PopNode = Q.top().second;
		int PopTime = Q.top().first;
		Q.pop();
		 
		for (int i = 0; i < Adj[PopNode].size(); i++)
		{
			if (KthMin[Adj[PopNode][i].first].size() < K)
			{
				KthMin[Adj[PopNode][i].first].push(PopTime + Adj[PopNode][i].second);
				Q.push(pair<int, int>(PopTime + Adj[PopNode][i].second, Adj[PopNode][i].first));
			}
			else if (KthMin[Adj[PopNode][i].first].top() > PopTime + Adj[PopNode][i].second)
			{
				KthMin[Adj[PopNode][i].first].pop();
				KthMin[Adj[PopNode][i].first].push(PopTime + Adj[PopNode][i].second);
				Q.push(pair<int, int>(PopTime + Adj[PopNode][i].second, Adj[PopNode][i].first));
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (KthMin[i].size() == K)
		{
			cout << KthMin[i].top() << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}


	return 0;
}
