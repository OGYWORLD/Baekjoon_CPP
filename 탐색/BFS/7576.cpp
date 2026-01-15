#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int DIRECTION_NUM = 4;

struct coordinateInfo
{
    int tomatoI;
    int tomatoJ;
    int tomatoDay;
};

int deltaI[] = {-1, 1, 0, 0};
int deltaJ[] = {0, 0, -1, 1};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m));
    queue<coordinateInfo> q;

    int unripe = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 0)
            {
                unripe++;
            }
            else if (box[i][j] == 1)
            {
                q.push({ i, j, 0 });
            }
        }
    }

    if (unripe == 0)
    {
        cout << 0;
        return 0;
    }

    int lastDay = 0;
    while (!q.empty())
    {
        int curI = q.front().tomatoI;
        int curJ = q.front().tomatoJ;
        int curDay = q.front().tomatoDay;
        q.pop();

        lastDay = curDay;
        
        for (int i = 0; i < DIRECTION_NUM; i++)
        {
            int nextI = deltaI[i] + curI;
            int nextJ = deltaJ[i] + curJ;
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) continue;
            if (box[nextI][nextJ] != 0) continue;

            box[nextI][nextJ] = 1;
            unripe--;
            q.push({ nextI, nextJ, curDay + 1 });
        }
    }

    if (unripe == 0)
    {
        cout << lastDay;
    }
    else
    {
        cout << -1;
    }

    return 0;
}