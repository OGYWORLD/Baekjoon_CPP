#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int result;

void MakeBigNum(int cur, int n, vector<int>& v, int k)
{
    if (cur > n)
    {
        return;
    }

    result = max(result, cur);

    for (int i = 0; i < k; i++)
    {
        MakeBigNum(cur * 10 + v[i], n, v, k);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    MakeBigNum(0, n, v, k);

    cout << result;

    return 0;
}