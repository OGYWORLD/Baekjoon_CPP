#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

static vector<tuple<int, int, int>> AdjTuple;
static vector<long> MaxCost;
static vector<int> EarnPerCity;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, DepartureCity, ArrivalCity, M;
	cin >> N >> DepartureCity >> ArrivalCity >> M;

	int SrtNode, EndNode, Cost;
	for (int i = 0; i < M; i++)
	{
		cin >> SrtNode >> EndNode >> Cost;
		AdjTuple.push_back(make_tuple(SrtNode, EndNode, Cost));
	}

	EarnPerCity.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> EarnPerCity[i];
	}
	MaxCost.resize(N, LONG_MIN);
	MaxCost[DepartureCity] = EarnPerCity[DepartureCity];

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int SrtNode = get<0>(AdjTuple[j]);
			int EndNode = get<1>(AdjTuple[j]);
			int Cost = get<2>(AdjTuple[j]);

			if (MaxCost[SrtNode] != LONG_MIN && MaxCost[EndNode] < MaxCost[SrtNode] + EarnPerCity[EndNode] - Cost)
			{
				MaxCost[EndNode] = MaxCost[SrtNode] + EarnPerCity[EndNode] - Cost;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int SrtNode = get<0>(AdjTuple[j]);
			int EndNode = get<1>(AdjTuple[j]);
			int Cost = get<2>(AdjTuple[j]);


			if (MaxCost[SrtNode] != LONG_MIN && MaxCost[EndNode] < MaxCost[SrtNode] + EarnPerCity[EndNode] - Cost)
			{
				MaxCost[EndNode] = LONG_MAX;
			}

			if (MaxCost[SrtNode] == LONG_MAX)
			{
				MaxCost[EndNode] = LONG_MAX;
			}
		}
	}

	if (MaxCost[ArrivalCity] == LONG_MAX)
	{
		cout << "Gee";
	}
	else if (MaxCost[ArrivalCity] == LONG_MIN)
	{
		cout << "gg";
	}
	else
	{
		cout << MaxCost[ArrivalCity];
	}


	return 0;
}
