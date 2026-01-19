#include <iostream>
#include <vector>

using namespace std;

int deltaI[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int deltaJ[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

const int DELTA_NUM = 8;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int r, c;
        cin >> r >> c;

        if (r == 0 && c == 0)
        {
            break;
        }

        vector<vector<int>> result(r, vector<int>(c, 0));
        vector<vector<char>> map(r, vector<char>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] == '*')
                {
                    result[i][j] = -1;
                    continue;
                }

                for (int idx = 0; idx < DELTA_NUM; idx++)
                {
                    int checkI = deltaI[idx] + i;
                    int checkJ = deltaJ[idx] + j;

                    if (checkI < 0 || checkI >= r || checkJ < 0 || checkJ >= c)
                    {
                        continue;
                    }

                    if (map[checkI][checkJ] == '*')
                    {
                        result[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (result[i][j] == -1)
                {
                    cout << '*';
                }
                else
                {
                    cout << result[i][j];
                }
            }
            cout << "\n";
        }

    }

    return 0;
}