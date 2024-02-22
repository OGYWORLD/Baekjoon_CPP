#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> Adj;
vector<int> IsVisited;
vector<int> Length;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> Adj(N + 1);
	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		Adj[A].push_back(B);
	}

	Adj.resize(N + 1);
	IsVisited.resize(N + 1, false);
	Length.resize(N + 1, 300001);

	queue<int> Q;
	Q.push(X);
	Length[X] = 0;
	while (Q.size() != 0)
	{
		int PopEntity = Q.front();
		Q.pop();

		IsVisited[PopEntity] = true;

		for (int i = 0; i < Adj[PopEntity].size(); i++)
		{
			if (!IsVisited[Adj[PopEntity][i]])
			{
				Q.push(Adj[PopEntity][i]);
				if (Length[Adj[PopEntity][i]] > Length[PopEntity] + 1)
				{
					Length[Adj[PopEntity][i]] = Length[PopEntity] + 1;
				}
			}
		}
	}
	

	int Cnt = 0;
	for (int i = 1; i < Length.size(); i++)
	{
		if (Length[i] == K)
		{
			cout << i << "\n";
			Cnt++;
		}
	}

	if (Cnt == 0)
	{
		cout << "-1";
	}

	return 0;
}
