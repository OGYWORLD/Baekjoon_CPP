#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int DELTA = 4;

int deltaX[] = { 0, 0, -1, 1 };
int deltaY[] = { -1, 1, 0, 0 };

int n;

vector<vector<bool>> isVisited;
vector<vector<char>> adjNon;
vector<vector<char>> adjRG;

int nonRedGreen;
int redGreen;

void DFSNonRedGreen(int i, int j);
void DFSRedGreen(int i, int j);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    adjNon.resize(n, vector<char>(n));
    adjRG.resize(n, vector<char>(n));
    isVisited.resize(n, vector<bool>(n, false));

    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            adjNon[i][j] = c;
            if (c == 'G')
            {
                adjRG[i][j] = 'R';
            }
            else
            {
                adjRG[i][j] = c;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j])
            {
                nonRedGreen++;
                DFSNonRedGreen(i, j);
            }
        }
    }

    isVisited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j])
            {
                redGreen++;
                DFSRedGreen(i, j);
            }
        }
    }

    cout << nonRedGreen << " " << redGreen;

    return 0;
}

void DFSNonRedGreen(int i, int j)
{
    isVisited[i][j] = true;

    for (int idx = 0; idx < DELTA; idx++)
    {
        int currentI = deltaY[idx] + i;
        int currentJ = deltaX[idx] + j;
        if (currentI > -1 && currentI < n && currentJ > -1 && currentJ < n)
        {
            if (adjNon[i][j] == adjNon[currentI][currentJ] &&
                !isVisited[currentI][currentJ])
            {
                DFSNonRedGreen(currentI, currentJ);
            }
        }
    }
}

void DFSRedGreen(int i, int j)
{
    isVisited[i][j] = true;

    for (int idx = 0; idx < DELTA; idx++)
    {
        int currentI = deltaY[idx] + i;
        int currentJ = deltaX[idx] + j;
        if (currentI > -1 && currentI < n && currentJ > -1 && currentJ < n)
        {
            if (adjRG[i][j] == adjRG[currentI][currentJ] &&
                !isVisited[currentI][currentJ])
            {
                DFSRedGreen(currentI, currentJ);
            }
        }
    }
}
