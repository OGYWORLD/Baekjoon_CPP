#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> Adj;
static vector<bool> IsVisited;
static vector<int> VisitGroup;

static bool IsBinaryGraph = true;

void DFS(int Node)
{
	IsVisited[Node] = true;

	for (int i = 0; i < Adj[Node].size(); i++)
	{
		if (!IsVisited[Adj[Node][i]])
		{
			VisitGroup[Adj[Node][i]] = (VisitGroup[Node] + 1) % 2;
			DFS(Adj[Node][i]);
		}
		else if (VisitGroup[Node] == VisitGroup[Adj[Node][i]])
		{
			IsBinaryGraph = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	int index = 0;
	int V, E, u, v;

	while (index < K)
	{
		cin >> V >> E;

		Adj.resize(V + 1);
		IsVisited.resize(V + 1, false);
		VisitGroup.resize(V + 1, 0);
		IsBinaryGraph = true;

		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}

		for (int i = 1; i <= V; i++)
		{
			if (IsBinaryGraph)
			{
				DFS(i);
			}
			else
			{
				break;
			}
		}

		if (IsBinaryGraph)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}

		for (int i = 0; i <= V; i++)
		{
			Adj[i].clear();
			IsVisited[i] = false;
			VisitGroup[i] = 0;
		}


		index++;
	}

	return 0;
}
