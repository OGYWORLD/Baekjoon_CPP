#include <iostream>
#include <vector>

using namespace std;

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

int r, c, k;
vector<char> adj[5];
bool isVisited[5][5];

int result;

void DFS(int v, int h, int d);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c >> k;

    char route;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> route;

            adj[i].push_back(route);
        }
    }

    isVisited[r - 1][0] = true;
    DFS(r-1, 0, 0);

    cout << result;

    return 0;
}

void DFS(int v, int h, int d)
{
    if (d == k - 1 && v == 0 && h == c - 1)
    {
        result++;
        return;
    }

    if (d > k - 2) return;

    for (int i = 0; i < 4; ++i)
    {
        int curV = deltaX[i] + v;
        int curH = deltaY[i] + h;
        
        if (curV > -1 && curV < r && curH > -1 && curH < c && !isVisited[curV][curH] && adj[curV][curH] != 'T')
        {
            isVisited[curV][curH] = true;
            DFS(curV, curH, d + 1);
            isVisited[curV][curH] = false;
        }
    }

}
