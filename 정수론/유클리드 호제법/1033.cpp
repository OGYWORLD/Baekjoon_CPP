#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

static vector<tuple<int, int, int>> Adj[10];
static long long Result[10];
static bool IsVisited[10];

long long GCD(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		long long r = a % b;
		return GCD(b, r);
	}
}

void DFS(int Node)
{
	IsVisited[Node] = true;

	for (tuple<int, int, int> i : Adj[Node])
	{
		int NN = get<0>(i);
		if (!IsVisited[NN])
		{
			Result[NN] = Result[Node] * get<2>(i) / get<1>(i);

			DFS(NN);
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

	long long LCM = 1;
	int a, b, p, q;
	for (int i = 0; i < N-1; i++)
	{
		cin >> a >> b >> p >> q;

		Adj[a].push_back(make_tuple(b, p, q));
		Adj[b].push_back(make_tuple(a, q, p));

		LCM *= p * q / GCD(p, q);
	}

	Result[0] = LCM;
	DFS(0);

	long long TotalGCD = Result[0];
	for (int i = 1; i < N; i++)
	{
		TotalGCD = GCD(TotalGCD, Result[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << Result[i] / TotalGCD << " ";
	}

	return 0;
}
