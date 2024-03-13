#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> Adj;
static vector<int> DepthAr;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Adj.resize(N + 1);
	DepthAr.resize(N + 1, 0);

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		Adj[A].push_back(B);
		DepthAr[B]++;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (DepthAr[i] == 0)
		{
			Q.push(i);
		}
	}

	while (Q.size() != 0)
	{
		int Result = Q.front();
		Q.pop();
		cout << Result << " ";

		for (int i = 0; i < Adj[Result].size(); i++)
		{
			DepthAr[Adj[Result][i]]--;

			if (DepthAr[Adj[Result][i]] == 0)
			{
				Q.push(Adj[Result][i]);
			}
		}
	}

	return 0;
}
