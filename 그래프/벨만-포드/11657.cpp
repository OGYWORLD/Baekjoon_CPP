#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> Edge;
static vector<Edge> Adj;
static vector<long> MinTime;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	MinTime.resize(N + 1, LONG_MAX);
	MinTime[1] = 0;

	int Srt, End, Time;
	for (int i = 0; i < M; i++)
	{
		cin >> Srt >> End >> Time;

		Adj.push_back(make_tuple(Srt, End, Time));
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int Srt = get<0>(Adj[j]);
			int End = get<1>(Adj[j]);
			int Time = get<2>(Adj[j]);

			if (MinTime[Srt] != LONG_MAX && MinTime[End] > MinTime[Srt] + Time)
			{
				MinTime[End] = MinTime[Srt] + Time;
			}
		}
	}

	bool bCycleExist = false;

	for (int i = 0; i < M; i++)
	{
		int Srt = get<0>(Adj[i]);
		int End = get<1>(Adj[i]);
		int Time = get<2>(Adj[i]);

		if (MinTime[Srt] != LONG_MAX && MinTime[End] > MinTime[Srt] + Time)
		{
			bCycleExist = true;
			break;
		}
	}

	if (!bCycleExist)
	{
		for (int i = 2; i <= N; i++)
		{
			if (MinTime[i] == LONG_MAX)
			{
				cout << "-1\n";
			}
			else
			{
				cout << MinTime[i] << "\n";
			}
		}
	}
	else
	{
		cout << "-1";
	}

	return 0;
}
