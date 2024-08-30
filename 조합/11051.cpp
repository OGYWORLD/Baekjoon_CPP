#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> dpTable(1001);
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			dpTable[i].push_back(0);
		}
	}

	for (int i = 0; i <= n; i++)
	{
		dpTable[i][1] = i;
		dpTable[i][0] = 1;
		dpTable[i][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dpTable[i][j] = dpTable[i - 1][j] + dpTable[i - 1][j - 1];
			dpTable[i][j] %= 10007;
		}
	}

	cout << dpTable[n][k];

	return 0;
}
