#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;
    int aa;
    long long dex = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> aa;
        dex = dex * a + aa;
    }

    vector<int> v;
    while (true)
    {
        if (dex == 0) break;
        v.push_back(dex % b);
        dex /= b;
    }

    for (int i = v.size() - 1; i > -1; i--)
    {
        cout << v[i] << " ";
    }

    return 0;
}