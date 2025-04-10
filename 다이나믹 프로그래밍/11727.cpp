#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAGIC_NUM = 10007;
    const int MAX = 1001;
    vector<int> dp(MAX);

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i < MAX; i++)
    {
        dp[i] = ((dp[i - 1] % MAGIC_NUM) + ((2 * (dp[i - 2]) % MAGIC_NUM))) % MAGIC_NUM;
    }

    int n;
    cin >> n;
    cout << dp[n];

    return 0;
}
