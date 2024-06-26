#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adjList[100001];
bool isVisted[100001];

vector<int> result;

void DFS(int n);

int index = 1;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;

	result.resize(n+1, 0);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	DFS(r);

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << "\n";
	}


	return 0;
}

void DFS(int n)
{
	result[n] = index;
	index++;
	isVisted[n] = true;

	sort(adjList[n].begin(), adjList[n].end());

	for (int i = 0; i < adjList[n].size(); i++)
	{
		if (!isVisted[adjList[n][i]])
		{
			DFS(adjList[n][i]);
		}
	}
}