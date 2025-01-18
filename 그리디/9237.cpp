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

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        v[i] += i+1;

        if (v[i] > max)
        {
            max = v[i];
        }
    }

    cout << max + 1;


    return 0;
}