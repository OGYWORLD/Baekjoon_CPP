#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> adj[501];
bool isVisited[501][501];

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

int paperCnt;
int curSize = 0;
int totalMax = 0;

void DFS(int x, int y);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    int image;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> image;

            adj[i].push_back(image);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!isVisited[i][j] && adj[i][j] != 0)
            {
                isVisited[i][j] = true;
                DFS(i, j);

                paperCnt++;

                if (totalMax < curSize) totalMax = curSize;
                
                curSize = 0;
            }
        }
    }

    cout << paperCnt << "\n" << totalMax;

    return 0;
}

void DFS(int x, int y)
{
    curSize++;

    for (int i = 0; i < 4; ++i)
    {
        int curX = deltaX[i] + x;
        int curY = deltaY[i] + y;
        if (curX > -1 && curX < n && curY > -1 && curY < m && !isVisited[curX][curY] && adj[curX][curY] != 0)
        {
            isVisited[curX][curY] = true;
            DFS(curX, curY);
        }
    }
}
