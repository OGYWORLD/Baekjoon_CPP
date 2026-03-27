#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    l--;

    sort(v.begin() + l, v.begin() + r);

    bool isBigger = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            isBigger = false;
        }
    }

    if (isBigger)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}