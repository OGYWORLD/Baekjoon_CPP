#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info
{
    int i;
    int j;
};

vector<vector<int>> grid;
vector<vector<int>> dist;

queue<info> q;

const int DELTA_NUM = 4;
int deltaJ[] = { 0, 0, -1, 1 };
int deltaI[] = { -1, 1, 0, 0 };

int n, m;
pair<int, int> target;

void GetDistance();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        vector<int> temp;
        vector<int> tempDist;
        for (int j = 0; j < m; j++)
        {
            cin >> a;

            if (a == 2)
            {
                target = make_pair(i, j);
            }

            temp.push_back(a);
            tempDist.push_back(-1);
        }
        grid.push_back(temp);
        dist.push_back(tempDist);
    }
    
    dist[target.first][target.second] = 0;
    q.push({ target.first, target.second });
    GetDistance();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0 || grid[i][j] == 2)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

void GetDistance()
{
    while (!q.empty())
    {
        info curInfo = q.front();
        q.pop();

        for (int idx = 0; idx < DELTA_NUM; idx++)
        {
            int nextI = deltaI[idx] + curInfo.i;
            int nextJ = deltaJ[idx] + curInfo.j;

            if (nextJ < 0 || nextJ >= m || nextI < 0 || nextI >= n) continue;

            if (dist[nextI][nextJ] == -1 && grid[nextI][nextJ] != 0)
            {
                dist[nextI][nextJ] = dist[curInfo.i][curInfo.j] + 1;
                q.push({ nextI, nextJ });
            }
        }
    }
}
