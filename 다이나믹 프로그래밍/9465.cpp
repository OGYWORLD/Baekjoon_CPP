#include <iostream>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> dp[2];
	vector<int> s[2];

	for (int i = 0; i < 100001; i++)
	{
		dp[0].push_back(0);
		dp[1].push_back(0);
		s[0].push_back(0);
		s[1].push_back(0);
	}

	int T;
	cin >> T;

	int n;
	int index = 0;
	int sticker;
	while (index < T)
	{
		cin >> n;

		int max = -1;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> sticker;
				s[i][j] = sticker;

				if (j == 0)
				{
					dp[i][0] = sticker;
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int curMax = -1;
				if (j - 1 > -1 && i - 1 > -1)
				{
					if (curMax < dp[j - 1][i - 1]) curMax = dp[j - 1][i - 1];

					if (i - 2 > -1)
					{
						if (curMax < dp[j - 1][i - 2]) curMax = dp[j - 1][i - 2];

						if (curMax < dp[j][i - 2]) curMax = dp[j][i - 2];
					}

					dp[j][i] = curMax + s[j][i];
				}
				else if (j + 1 < 2 && i - 1 > -1)
				{
					if (curMax < dp[j + 1][i - 1]) curMax = dp[j + 1][i - 1];

					if (i - 2 > -1)
					{
						if (curMax < dp[j][i - 2]) curMax = dp[j][i - 2];

						if (curMax < dp[j + 1][i - 2]) curMax = dp[j + 1][i - 2];
					}

					dp[j][i] = curMax + s[j][i];
				}

				if (dp[j][i] > max)
				{
					max = dp[j][i];
				}
			}
		}

		if (max == -1) max = s[0][0] > s[1][0] ? s[0][0] : s[1][0];

		cout << max << "\n";


		index++;
	}


	return 0;
}