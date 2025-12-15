#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.first < b.first;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        bool isSame = true;
        int total = 0;
        vector<pair<int,int>> v(n);
        cin >> v[0].first;
        v[0].second = 1;
        total += v[0].first;
        for (int j = 1; j < n; j++)
        {
            cin >> v[j].first;
            v[j].second = j + 1;

            total += v[j].first;
            if (v[j - 1].first != v[j].first)
            {
                isSame = false;
            }
        }

        sort(v.begin(), v.end(), Compare);

        if (isSame || (v[n - 1].first == v[n - 2].first))
        {
            cout << "no winner\n";
        }
        else
        {
            if (v[n - 1].first > total / 2)
            {
                cout << "majority winner " << v[n - 1].second << "\n";
            }
            else
            {
                cout << "minority winner " << v[n - 1].second << "\n";
            }
        }
    }

    return 0;
}
