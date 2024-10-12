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

    vector<int> glass(n);
    for (int i = 0; i < n; i++)
    {
        cin >> glass[i];
    }

    if (n == 1)
    {
        cout << glass[0];
        return 0;
    }

    vector<int> dp(n);
    dp[0] = glass[0];
    dp[1] = glass[0] + glass[1];

    if (n > 2)
    {
        dp[2] = max(dp[1], max(glass[0] + glass[2], glass[1] + glass[2]));
    }

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]));
    }

    cout << dp[n - 1];

    return 0;
}
