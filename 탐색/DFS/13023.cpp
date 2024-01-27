#include <iostream>
#include <vector>

using namespace std;

static vector<int> AdjVector[2001];
static bool IsVisited[2001];
static bool IsDFSFinished = false;

void DFS(int Node, int D)
{
	D++;
	if (D == 5 || IsDFSFinished)
	{
		IsDFSFinished = true;
		return;
	}
	IsVisited[Node] = true;

	for (int k = 0; k < AdjVector[Node].size(); k++)
	{
		if (!IsVisited[AdjVector[Node][k]])
		{
			DFS(AdjVector[Node][k], D);
		}
	}
	IsVisited[Node] = false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 2001; i++)
	{
		IsVisited[i] = false;
	}

	int N, M;
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		AdjVector[a].push_back(b);
		AdjVector[b].push_back(a);
	}

	int Depth = 0;
	for (int i = 0; i < N; i++)
	{
		DFS(i, Depth);
		if (IsDFSFinished)
		{
			break;
		}
	}

	if (IsDFSFinished)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}


	return 0;
}