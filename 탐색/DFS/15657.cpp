#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

static vector<vector<int>> Adj;

static vector<int> PrintEntity;

void DFS(int Node, int Depth, int& EndDepth)
{
	PrintEntity.push_back(Node);

	if (Depth == EndDepth)
	{
		bool bIsDecs = true;
		for (int i = 1; i < PrintEntity.size(); i++)
		{
			if (PrintEntity[i] - PrintEntity[i-1] < 0)
			{
				bIsDecs = false;
				break;
			}
			
		}
		if (bIsDecs)
		{
			for (int i = 0; i < PrintEntity.size(); i++)
			{
				cout << PrintEntity[i] << " ";

			}
			cout << "\n";
		}

		PrintEntity.pop_back();

		return;
	}
	else
	{
		for (int j = 0; j < Adj[Node].size(); j++)
		{
			DFS(Adj[Node][j], Depth + 1, EndDepth);
		}

		PrintEntity.pop_back();
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Adj.resize(10001);

	vector<int> GetEntity(N);
	for (int i = 0; i < N; i++)
	{
		cin >> GetEntity[i];
	}

	sort(GetEntity.begin(), GetEntity.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Adj[GetEntity[i]].push_back(GetEntity[j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		DFS(GetEntity[i], 1, M);

		PrintEntity.clear();
	}

	return 0;
}
