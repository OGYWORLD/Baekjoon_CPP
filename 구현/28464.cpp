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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int s = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2) s += v[i];
        else p += v[i];
    }

    cout << s << " " << p;

    return 0;
}