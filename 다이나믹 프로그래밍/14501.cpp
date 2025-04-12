#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    vector<pair<int, int>> table(n + 1);

    int t, p;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> p;

        table[i] = make_pair(t, p);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (table[i].first + i <= n)
        {
            dp[i] = max(dp[i + 1], table[i].second + dp[i + table[i].first]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0];

    return 0;
}
