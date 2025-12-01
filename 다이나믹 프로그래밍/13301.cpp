#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<long long> dp(81);

    dp[1] = 4;
    dp[2] = 6;
    for (int i = 3; i <= 80; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n;
    cin >> n;
    cout << dp[n];

    return 0;
}