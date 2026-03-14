#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> names(n);
    vector<int> powers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> names[i] >> powers[i];
    }

    for (int i = 0; i < m; i++)
    {
        int charaPower;
        cin >> charaPower;

        int idx = lower_bound(powers.begin(), powers.end(), charaPower) - powers.begin();
        cout << names[idx] << "\n";
    }

    return 0;
}