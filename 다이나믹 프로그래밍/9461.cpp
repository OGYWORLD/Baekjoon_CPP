#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAX_N = 100;
    vector<long long> dp(MAX_N + 1);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= MAX_N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}