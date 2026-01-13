#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAX_N = 50000;
    vector<int> dp(MAX_N + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= MAX_N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    int n;
    cin >> n;

    cout << dp[n];

    return 0;
}