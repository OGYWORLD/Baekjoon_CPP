#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> Adj;
static vector<vector<int>> IsVisited;
static vector<int> Result;
static int Depth = 0;

static int YDelta[] = { 0, 0, -1, 1 };
static int XDelta[] = {-1, 1, 0, 0};

void DFS(int XNode, int YNode, int& N)
{
	Depth++;
	IsVisited[XNode][YNode] = true;

	for (int i = 0; i < 4; i++)
	{
		if (XDelta[i] + XNode < 0 || XDelta[i] + XNode >= N || YDelta[i] + YNode < 0 || YDelta[i] + YNode >= N)
		{
			continue;
		}
		else
		{
			if (!IsVisited[XDelta[i] + XNode][YDelta[i] + YNode] && Adj[XDelta[i] + XNode][YDelta[i] + YNode] != 0)
			{
				DFS(XDelta[i] + XNode, YDelta[i] + YNode, N);
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	Adj.resize(N);
	IsVisited.resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			IsVisited[i].push_back(false);
		}
	}

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			Adj[i].push_back(s[j] - '0');
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!IsVisited[i][j] && Adj[i][j] != 0)
			{
				DFS(i, j, N);

				Result.push_back(Depth);
				Depth = 0;
			}
		}
	}

	cout << Result.size() << "\n";

	sort(Result.begin(), Result.end());
	for (int i = 0; i < Result.size(); i++)
	{
		cout << Result[i] << "\n";
	}

	return 0;
}
