#include <iostream>
#include <vector>

using namespace std;

static vector<int> Adj[101];
static vector<bool> IsVisited(101, false);
static int Cnt = 0;

void DFS(int Node)
{
	if (!IsVisited[Node])
	{
		IsVisited[Node] = true;
		Cnt++;
		for (int i = 0; i < Adj[Node].size(); i++)
		{
			if (!IsVisited[Adj[Node][i]])
			{
				DFS(Adj[Node][i]);
			}
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

	int c1, c2;
	for (int i = 0; i < M; i++)
	{
		cin >> c1 >> c2;

		Adj[c1].push_back(c2);
		Adj[c2].push_back(c1);
	}

	DFS(1);
	Cnt--;
	cout << Cnt;
	
	return 0;
}
