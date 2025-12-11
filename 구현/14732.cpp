#include <iostream>
#include <vector>

using namespace std;

void Coloring(vector<vector<int>>& place, int x1, int y1, int x2, int y2);
int CheckColored(vector<vector<int>>& place);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> place;
    for (int i = 0; i <= 500; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= 500; j++)
        {
            temp.push_back(0);
        }
        place.push_back(temp);
    }

    int n;
    cin >> n;

    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Coloring(place, x1, y1, x2, y2);
    }

    cout << CheckColored(place);

    return 0;
}

void Coloring(vector<vector<int>>& place, int x1, int y1, int x2, int y2)
{
    for (int i = y1; i < y2; i++)
    {
        for (int j = x1; j < x2; j++)
        {
            place[i][j] = 1;
        }
    }
}

int CheckColored(vector<vector<int>>& place)
{
    int result = 0;
    for (int i = 0; i <= 500; i++)
    {
        for (int j = 0; j <= 500; j++)
        {
            if (place[i][j] == 1) result++;
        }
    }

    return result;
}
