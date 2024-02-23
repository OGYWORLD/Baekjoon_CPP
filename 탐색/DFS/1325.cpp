#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> Adj;
static vector<bool> IsVisited;
static vector<pair<int, int>> Result;
static int Depth = 0;

void DFS(int Node)
{
	Depth++;
	IsVisited[Node] = true;

	for (int i = 0; i < Adj[Node].size(); i++)
	{
		if (!IsVisited[Adj[Node][i]])
		{
			DFS(Adj[Node][i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Adj.resize(N + 1);
	IsVisited.resize(N + 1, false);

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		Adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!IsVisited[i])
		{
			DFS(i);
		}

		Result.push_back(pair<int, int>(Depth, i));

		IsVisited.clear();
		IsVisited.resize(N + 1, false);
		Depth = 0;
	}

	sort(Result.begin(), Result.end());

	int RS = Result.size();
	int MaxHackCnt = Result[RS - 1].first;

	for (int i = 0; i < RS; i++)
	{
		if (MaxHackCnt == Result[i].first)
		{
			cout << Result[i].second << " ";
		}
	}


	return 0;
}
