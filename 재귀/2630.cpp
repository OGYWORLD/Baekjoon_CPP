#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;

int blue = 0;
int white = 0;

void CheckPaper(int row, int col, int size);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int b;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> b;
            temp.push_back(b);
        }
        paper.push_back(temp);
    }

    CheckPaper(0, 0, n);

    cout << white << "\n" << blue;

    return 0;
}

void CheckPaper(int row, int col, int size)
{
    if (size == 1)
    {
        if (paper[row][col] == 0) white++;
        else blue++;

        return;
    }

    bool isNeedDivide = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (paper[row][col] != paper[row + i][col + j])
            {
                isNeedDivide = true;
                break;
            }
        }
        if (isNeedDivide)
        {
            break;
        }
    }

    if (!isNeedDivide)
    {
        if (paper[row][col] == 0) white++;
        else blue++;
             
        return;
    }
    else
    {
        int y[] = { row, row, row + size / 2, row + size / 2 };
        int x[] = { col, col + size / 2, col, col + size / 2 };
        for (int i = 0; i < 4; i++)
        {
            CheckPaper(y[i], x[i], size / 2);
        }
    }
}