#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> Adj;
static vector<bool> IsVisited;
static vector<int> PrintVector;

void BackTracking(int depth, int& M, int& N)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << PrintVector[i] << " ";
		}

		cout << "\n";
	}
	else
	{
		int BeforeNode = -1;

		for (int i = 0; i < N; i++)
		{
			if (!IsVisited[i] && Adj[i] != BeforeNode)
			{
				PrintVector[depth] = Adj[i];
				BeforeNode = Adj[i];
				IsVisited[i] = true;
				BackTracking(depth + 1, M, N);
				IsVisited[i] = false;
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

	IsVisited.resize(N, false);
	Adj.resize(N);
	PrintVector.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Adj[i];
	}

	sort(Adj.begin(), Adj.end());

	BackTracking(0, M, N);

	

	return 0;
}
