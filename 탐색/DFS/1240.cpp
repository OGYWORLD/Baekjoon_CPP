#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjVector[1001];
bool isVisited[1001];

void DFS(int srt, int end, int cost);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int srt, end, c;
	for (int i = 0; i < n-1; i++)
	{
		cin >> srt >> end >> c;

		adjVector[srt].push_back(pair<int, int>(end, c));
		adjVector[end].push_back(pair<int, int>(srt, c));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> srt >> end;
		DFS(srt, end, 0);
	}


	return 0;
}

void DFS(int srt, int end, int cost)
{
	if (srt == end)
	{
		cout << cost << "\n";
		return;
	}

	isVisited[srt] = true;

	for (int k = 0; k < adjVector[srt].size(); k++)
	{
		if (!isVisited[adjVector[srt][k].first])
		{
			DFS(adjVector[srt][k].first, end, cost + adjVector[srt][k].second);
		}
	}


	isVisited[srt] = false;
}
