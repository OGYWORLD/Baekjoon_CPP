#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> isVisited;
int n, m;
bool isReached = false;

int deltaX[] = { 1, 0 };
int deltaY[] = { 0, 1 };

const int DIRECT_NUM = 2;

void DFS(int i, int j);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        vector<bool> boolTemp(n);
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            cin >> temp[j];
            boolTemp[j] = false;
        }

        adj.push_back(temp);
        isVisited.push_back(boolTemp);
    }

    DFS(0, 0);

    if (isReached)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}

void DFS(int i, int j)
{
    if (isReached)
    {
        return;
    }

    isVisited[i][j] = true;

    if (i == m - 1 && j == n - 1)
    {
        isReached = true;
        return;
    }
    else
    {
        for (int idx = 0; idx < DIRECT_NUM; idx++)
        {
            int tempY = i + deltaY[idx];
            int tempX = j + deltaX[idx];
            if (tempY > -1 && tempX > -1 && tempY < m && tempX < n && !isVisited[tempY][tempX] && adj[tempY][tempX] != 0)
            {
                DFS(tempY, tempX);
            }
        }
    }
}
