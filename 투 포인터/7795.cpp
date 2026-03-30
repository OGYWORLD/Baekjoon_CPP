#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> aVector(n);
        vector<int> bVector(m);

        for (int i = 0; i < n; i++)
        {
            cin >> aVector[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> bVector[i];
        }

        sort(aVector.begin(), aVector.end());
        sort(bVector.begin(), bVector.end());

        int j = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < m && bVector[j] < aVector[i])
            {
                j++;
            }

            count += j;
        }

        cout << count << "\n";
    }

    return 0;
}