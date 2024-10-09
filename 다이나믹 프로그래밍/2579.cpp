#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class EStair
{
	ONE_STEP,
	TWO_STEP
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int stair;
	vector<pair<int, int>> dp[2]; // 0: 1칸씩, 1: 2칸씩

	int index = 0;
	while (index < n)
	{
		cin >> stair;

		if (index == 0)
		{
			dp[(int)EStair::ONE_STEP].push_back(pair<int, int>(stair, 1));
			dp[(int)EStair::TWO_STEP].push_back(pair<int, int>(0, 0));
		}
		else if (index == 1)
		{
			dp[(int)EStair::ONE_STEP].push_back(pair<int, int>(stair + dp[(int)EStair::ONE_STEP][0].first, 2));
			dp[(int)EStair::TWO_STEP].push_back(pair<int, int>(stair, 0));
		}
		else
		{
			if (dp[(int)EStair::ONE_STEP][index - 1].first > dp[(int)EStair::TWO_STEP][index - 1].first) // 1칸 -> 1칸
			{
				if (dp[(int)EStair::ONE_STEP][index - 1].second == 2) // 만약 1칸 -> 1칸이 안 된다면
				{
					dp[(int)EStair::ONE_STEP].push_back(pair<int, int>(dp[(int)EStair::TWO_STEP][index - 1].first + stair, 2));
				}
				else
				{
					dp[(int)EStair::ONE_STEP].push_back(pair<int, int>(dp[(int)EStair::ONE_STEP][index - 1].first + stair, dp[(int)EStair::ONE_STEP][index - 1].second + 1));
				}
			}
			else // 2칸 -> 1칸
			{
				dp[(int)EStair::ONE_STEP].push_back(pair<int, int>(dp[(int)EStair::TWO_STEP][index - 1].first + stair, 2));
			}

			dp[(int)EStair::TWO_STEP].push_back(pair<int, int>(max(dp[(int)EStair::ONE_STEP][index - 2].first, dp[(int)EStair::TWO_STEP][index - 2].first) + stair, 1));
		}

		index++;
	}

	cout << max(dp[(int)EStair::ONE_STEP][n - 1].first, dp[(int)EStair::TWO_STEP][n - 1].first);

	return 0;
}