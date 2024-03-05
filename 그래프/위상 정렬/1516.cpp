#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;

vector<vector<int>> Adj;
vector<vector<int>> Adj2;
vector<int> Times;
vector<int> Times2;
vector<int> Connects;
vector<bool> IsVisited;
vector<int> Result;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	Adj.resize(N + 1);
	Adj2.resize(N + 1);
	Times.resize(N + 1);
	Times2.resize(N + 1);
	Connects.resize(N + 1);
	IsVisited.resize(N + 1, false);
	Result.resize(N + 1, 0);

	int GetTime;
	for (int i = 1; i <= N; i++)
	{
		cin >> GetTime;
		Times[i] = GetTime;
		Times2[i] = GetTime;

		int PreConstruct;
		while (1)
		{
			cin >> PreConstruct;
			if (PreConstruct == -1)
			{
				break;
			}

			Adj[i].push_back(PreConstruct);
			Adj2[PreConstruct].push_back(i);
			Connects[i]++;
		}
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (Connects[i] == 0)
		{
			Q.push(i);
		}
	}

	while (Q.size() != 0)
	{
		int GetOutEntity = Q.front();
		Q.pop();

		int Max = Result[GetOutEntity];
		for (int i = 0; i < Adj[GetOutEntity].size(); i++)
		{
			if (Max < Times[Adj[GetOutEntity][i]])
			{
				Max = Times[Adj[GetOutEntity][i]];
			}
		}

		Result[GetOutEntity] = Max;
		Times[GetOutEntity] += Max;

		for (int i = 0; i < Adj2[GetOutEntity].size(); i++)
		{
			Connects[Adj2[GetOutEntity][i]]--;

			if (Connects[Adj2[GetOutEntity][i]] == 0)
			{
				Q.push(Adj2[GetOutEntity][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		Result[i] += Times2[i];
		cout << Result[i] << "\n";
	}

	return 0;
}
