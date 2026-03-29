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

    vector<int> v(n);

    vector<int> cnt(5, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int result = 0;

    result += cnt[4];

    int pair31 = min(cnt[3], cnt[1]);
    result += cnt[3];
    cnt[1] -= pair31;

    result += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2] == 1)
    {
        result++;
        cnt[1] = max(0, cnt[1] - 2);
    }

    result += (cnt[1] + 3) / 4;

    cout << result;

    return 0;
}