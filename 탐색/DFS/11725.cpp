#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Adj;
vector<int> ParentVector;
vector<bool> IsVisited;

void FindParent(int Node, int YourParent)
{
	ParentVector[Node] = YourParent;
	IsVisited[Node] = true;

	for (int i = 0; i < Adj[Node].size(); i++)
	{
		if (!IsVisited[Adj[Node][i]])
		{
			FindParent(Adj[Node][i], Node);
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

	Adj.resize(N + 1);
	ParentVector.resize(N + 1);
	IsVisited.resize(N + 1);

	int A, B;
	for (int i = 0; i < N-1; i++)
	{
		cin >> A >> B;

		Adj[A].push_back(B);
		Adj[B].push_back(A);
	}

	FindParent(1, -1);

	for (int i = 2; i <= N; i++)
	{
		cout << ParentVector[i] << "\n";
	}

	return 0;
}
