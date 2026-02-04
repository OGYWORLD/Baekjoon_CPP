#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> bad(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (bad[i][j]) continue;

            for (int k = j + 1; k <= n; k++)
            {
                if (bad[i][k]) continue;
                if (bad[j][k]) continue;

                count++;
            }
        }
    }

    cout << count;

    return 0;
}