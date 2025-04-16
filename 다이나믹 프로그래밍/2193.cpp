#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAX_N = 91;
    vector<long long> dp(MAX_N, 0);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i < MAX_N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;
    cin >> n;

    cout << dp[n];

    return 0;
}
