#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> Table;

	int N, M;

	cin >> N >> M;

	int Entity;
	int TotalSum = 0;
	for (int i = 0; i < N * N; i++)
	{
		cin >> Entity;
		TotalSum += Entity;
		Table.push_back(TotalSum);

		if ((i + 1) % N == 0)
		{
			TotalSum = 0;
		}
	}

	int X1, Y1, X2, Y2;
	int Result = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		
		for (int j = X1 - 1; j <= X2 - 1; j++)
		{
			if (Y1 == 1)
			{
				Result += Table[j * N + (Y2 - 1)];
			}
			else
			{
				Result += Table[j * N + (Y2 - 1)] - Table[j * N + (Y1 - 1) - 1];
			}
		}
		
		cout << Result << "\n";

		Result = 0;

	}

	
	return 0;
}
