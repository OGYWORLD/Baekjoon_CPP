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

    sort(v.begin(), v.end(), greater<int>());

    int qIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= i + 1)
        {
            qIndex = i + 1;
        }
    }

    cout << qIndex;

    return 0;
}