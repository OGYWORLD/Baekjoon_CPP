#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static bool IsVisitedDFS[1001];
static bool IsVisitedBFS[1001];
static vector<int> AdjVector[1001];

void DFS(int v)
{
	cout << v << " ";
	IsVisitedDFS[v] = true;

	for (int i = 0; i < AdjVector[v].size(); i++)
	{
		if (!IsVisitedDFS[AdjVector[v][i]])
		{
			DFS(AdjVector[v][i]);
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		AdjVector[a].push_back(b);
		AdjVector[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(AdjVector[i].begin(), AdjVector[i].end());
	}

	DFS(V);

	cout << "\n";

	queue<int> BFSQueue;
	BFSQueue.push(V);
	IsVisitedBFS[V] = true;
	int VisitedNode;
	while (BFSQueue.size() != 0)
	{
		VisitedNode = BFSQueue.front();
		BFSQueue.pop();
		cout << VisitedNode << " ";

		for (int i = 0; i < AdjVector[VisitedNode].size(); i++)
		{
			if (!IsVisitedBFS[AdjVector[VisitedNode][i]])
			{
				BFSQueue.push(AdjVector[VisitedNode][i]);
				IsVisitedBFS[AdjVector[VisitedNode][i]] = true;
			}
		}
	}

	

	return 0;
}