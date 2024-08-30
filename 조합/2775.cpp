#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int apt[15][15];

	// 0층 세팅
	for (int i = 1; i < 15; i++)
	{
		apt[i][1] = 1;
		apt[0][i] = i;
	}

	// 점화식: D[k][n] = D[k-1][n] + D[k][n-1]
	for (int i = 1; i < 15; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
		}
	}

	int t;
	cin >> t;

	int k, n; // k층의 n호
	int index = 0;
	while (index < t)
	{
		cin >> k >> n;

		cout << apt[k][n] << "\n";

		index++;
	}


	return 0;
}

