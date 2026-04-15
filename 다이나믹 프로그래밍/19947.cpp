#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, y;
    cin >> h >> y;

    int dp[11];
    dp[0] = h;

    for (int i = 1; i <= y; i++)
    {
        dp[i] = dp[i - 1] * 1.05;

        if (i >= 3)
        {
            dp[i] = max(dp[i], (int)(dp[i - 3] * 1.20));
        }

        if (i >= 5)
        {
            dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
        }
    }

    cout << dp[y];

    return 0;
}