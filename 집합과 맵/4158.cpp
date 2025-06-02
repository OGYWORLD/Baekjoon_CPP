#include <iostream>
#include <unordered_set>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        int c;
        unordered_set<int> cd;

        for (int i = 0; i < n; i++)
        {
            cin >> c;
            cd.insert(c);
        }

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> c;
            if (cd.find(c) != cd.end()) result++;
        }

        cout << result << '\n';
    }

    return 0;
}
