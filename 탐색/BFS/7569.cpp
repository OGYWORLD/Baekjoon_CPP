#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position
{
    int x;
    int y;
    int z;
};

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n, h;
    cin >> m >> n >> h;

    queue<Position> q;

    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int tomato;
                cin >> tomato;
                box[i][j][k] = tomato;

                if (tomato == 1)
                {
                    q.push(Position{ k, j, i });
                }
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            int nextZ = z + dz[i];

            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && nextZ >= 0 && nextZ < h &&
                box[nextZ][nextY][nextX] == 0)
            {
                box[nextZ][nextY][nextX] = box[z][y][x] + 1;
                q.push(Position{ nextX, nextY, nextZ });
            }
        }
    }

    int maxVal = 1;

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (box[z][y][x] == 0)
                {
                    cout << -1;
                    return 0;
                }

                if (box[z][y][x] > maxVal)
                {
                    maxVal = box[z][y][x];
                }
            }
        }
    }

    cout << (maxVal - 1);

    return 0;
}