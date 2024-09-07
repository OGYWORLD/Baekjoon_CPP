#include <iostream>
#include <iomanip>

#define MAX_NUM	9

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	double d[MAX_NUM][MAX_NUM];

	for (int i = 1; i < MAX_NUM; i++)
	{
		d[i][i] = 1;
		d[i][0] = 1;
		d[i][1] = i;
	}

	for (int i = 2; i < MAX_NUM; i++)
	{
		for (int j = 1; j < i; j++)
		{
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
		}
	}

	int n, m, k;
	cin >> n >> m >> k;

	double upSum = 0;
	for (int i = k; i <= m; i++)
	{
		if (m < i || n - m < m - i)
		{
			continue;
		}

		upSum += d[m][i] * d[n - m][m - i];
	}

	double result = upSum / d[n][m];

	if (result > 1)
	{
		cout << 1.0;
	}
	else
	{
		cout << fixed << setprecision(9);
		cout << result;
	}


	return 0;
}

