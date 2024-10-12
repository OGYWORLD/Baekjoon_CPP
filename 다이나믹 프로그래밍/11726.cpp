#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	dp.resize(n+1, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	if (n < 3)
	{
		cout << dp[n];
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}

