#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<pair<int, int>>> blocks(19, vector<pair<int, int>>(4));

int maxCost = -1;
int n, m;

void SetBlocks();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    SetBlocks();

    cin >> n >> m;

    adj.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    for (int idx = 0; idx < blocks.size(); idx++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cost = 0;
                for (int k = 0; k < blocks[idx].size(); k++)
                {
                    int currentI = i + blocks[idx][k].first;
                    int currentJ = j + blocks[idx][k].second;
                    if (currentI > -1 && currentI < n && currentJ > -1 && currentJ < m)
                    {
                        cost += adj[currentI][currentJ];
                    }
                    else
                    {
                        cost = -1;
                        break;
                    }
                }

                if (cost > maxCost)
                {
                    maxCost = cost;
                }
            }
        }
    }

    cout << maxCost;

    return 0;
}

void SetBlocks()
{
    //
    blocks[0][0] = make_pair(0, 0);
    blocks[0][1] = make_pair(0, 1);
    blocks[0][2] = make_pair(0, 2);
    blocks[0][3] = make_pair(0, 3);

    blocks[1][0] = make_pair(0, 0);
    blocks[1][1] = make_pair(1, 0);
    blocks[1][2] = make_pair(2, 0);
    blocks[1][3] = make_pair(3, 0);

    //
    blocks[2][0] = make_pair(0, 0);
    blocks[2][1] = make_pair(1, 0);
    blocks[2][2] = make_pair(2, 0);
    blocks[2][3] = make_pair(2, 1);

    blocks[3][0] = make_pair(0, 0);
    blocks[3][1] = make_pair(0, 1);
    blocks[3][2] = make_pair(0, 2);
    blocks[3][3] = make_pair(1, 0);

    blocks[4][0] = make_pair(0, 0);
    blocks[4][1] = make_pair(0, 1);
    blocks[4][2] = make_pair(1, 1);
    blocks[4][3] = make_pair(2, 1);

    blocks[5][0] = make_pair(0, 0);
    blocks[5][1] = make_pair(0, 1);
    blocks[5][2] = make_pair(0, 2);
    blocks[5][3] = make_pair(-1, 2);

    //
    blocks[6][0] = make_pair(0, 0);
    blocks[6][1] = make_pair(1, 0);
    blocks[6][2] = make_pair(1, 1);
    blocks[6][3] = make_pair(2, 1);

    blocks[7][0] = make_pair(0, 0);
    blocks[7][1] = make_pair(0, 1);
    blocks[7][2] = make_pair(-1, 1);
    blocks[7][3] = make_pair(-1, 2);

    //
    blocks[8][0] = make_pair(0, 0);
    blocks[8][1] = make_pair(0, 1);
    blocks[8][2] = make_pair(1, 0);
    blocks[8][3] = make_pair(1, 1);

    //
    blocks[9][0] = make_pair(0, 0);
    blocks[9][1] = make_pair(0, 1);
    blocks[9][2] = make_pair(-1, 1);
    blocks[9][3] = make_pair(0, 2);

    blocks[10][0] = make_pair(0, 0);
    blocks[10][1] = make_pair(0, 1);
    blocks[10][2] = make_pair(0, 2);
    blocks[10][3] = make_pair(1, 1);

    blocks[11][0] = make_pair(0, 0);
    blocks[11][1] = make_pair(1, 0);
    blocks[11][2] = make_pair(2, 0);
    blocks[11][3] = make_pair(1, 1);

    blocks[12][0] = make_pair(0, 0);
    blocks[12][1] = make_pair(1, 0);
    blocks[12][2] = make_pair(2, 0);
    blocks[12][3] = make_pair(1, -1);

    blocks[13][0] = make_pair(0, 0);
    blocks[13][1] = make_pair(1, 0);
    blocks[13][2] = make_pair(2, 0);
    blocks[13][3] = make_pair(2, -1);

    blocks[14][0] = make_pair(0, 0);
    blocks[14][1] = make_pair(0, 1);
    blocks[14][2] = make_pair(0, 2);
    blocks[14][3] = make_pair(1, 2);

    blocks[15][0] = make_pair(0, 0);
    blocks[15][1] = make_pair(0, 1);
    blocks[15][2] = make_pair(1, 0);
    blocks[15][3] = make_pair(2, 0);

    blocks[16][0] = make_pair(0, 0);
    blocks[16][1] = make_pair(1, 0);
    blocks[16][2] = make_pair(1, 1);
    blocks[16][3] = make_pair(1, 2);

    blocks[17][0] = make_pair(0, 0);
    blocks[17][1] = make_pair(1, 0);
    blocks[17][2] = make_pair(1, -1);
    blocks[17][3] = make_pair(2, -1);

    blocks[18][0] = make_pair(0, 0);
    blocks[18][1] = make_pair(0, 1);
    blocks[18][2] = make_pair(1, 1);
    blocks[18][3] = make_pair(1, 2);
}