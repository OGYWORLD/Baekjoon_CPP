#include <iostream>
#include <vector>

using namespace std;

int deltaX[] = { -1, 1, 0, 0 };
int deltaY[] = { 0, 0, -1, 1 };

int r, c;
int sheepCnt, wolfCnt;
int curSheep, curWolf;
vector<char> adj[251];
bool isVisited[251][251];

void DFS(int v, int h);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    
    char route;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> route;

            adj[i].push_back(route);

            if (route == 'v') wolfCnt++;
            if (route == 'o') sheepCnt++;
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (!isVisited[i][j] && adj[i][j] != '#')
            {
                isVisited[i][j] = true;
                if (adj[i][j] == 'v') curWolf++;
                else if (adj[i][j] == 'o') curSheep++;

                DFS(i, j);

                if (curSheep > curWolf) wolfCnt -= curWolf;
                else if (curSheep <= curWolf) sheepCnt -= curSheep;

                curSheep = 0;
                curWolf = 0;
            }
        }
    }

    cout << sheepCnt << " " << wolfCnt;

    return 0;
}

void DFS(int v, int h)
{
    for (int i = 0; i < 4; ++i)
    {
        int curV = deltaX[i] + v;
        int curH = deltaY[i] + h;

        if (curV > -1 && curV < r && curH > -1 && curH < c && !isVisited[curV][curH] && adj[curV][curH] != '#')
        {
            isVisited[curV][curH] = true;
            if (adj[curV][curH] == 'v') curWolf++;
            else if (adj[curV][curH] == 'o') curSheep++;

            DFS(curV, curH);
        }
    }
}
