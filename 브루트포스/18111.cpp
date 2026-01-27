#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> ground(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ground[i][j];
        }
    }

    long long preTime = INT_MAX;
    int maxHight = 0;
    
    for (int h = 256; h >= 0; h--)
    {
        long long remove = 0;
        long long add = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int a = ground[i][j];
                if (a > h)
                {
                    remove += (a - h);
                }
                else
                {
                    add += (h - a);
                }
            }
        }

        if (b + remove < add) continue;

        long long time = remove * 2 + add;

        if (time < preTime)
        {
            preTime = time;
            maxHight = h;
        }
    }

    cout << preTime << " " << maxHight;
    
    return 0;
}