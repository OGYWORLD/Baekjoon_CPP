#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> dp(1000001);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < 1000001; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    int n;
    cin >> n;

    cout << dp[n];

    return 0;
}