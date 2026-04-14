#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 1, 0);

    int w, v;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;

        for (int j = k; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[k];

    return 0;
}