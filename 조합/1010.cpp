#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// DP Table 생성
	int d[30][30];

	for (int i = 0; i < 30; i++) // DP Table 초기화
	{
		d[i][0] = 1;
		d[i][i] = 1;
		d[i][1] = i;
	}

	for (int i = 2; i < 30; i++)
	{
		for (int j = 1; j < i; j++)
		{
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1]; // 조합 점화식
		}
	}


	int t;
	cin >> t;

	int n, m;
	int index = 0;
	while (index < t)
	{
		cin >> n >> m;

		cout << d[m][n] << "\n";

		index++;
	}

	return 0;
}

