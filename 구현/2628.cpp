#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindMax(vector<int>& v);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int row, col;
    cin >> row >> col;

    int n;
    cin >> n;

    vector<int> rows;
    vector<int> cols;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == 0) cols.push_back(b);
        else rows.push_back(b);
    }

    rows.push_back(row);
    cols.push_back(col);

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    int rowMax = FindMax(rows);
    int colMax = FindMax(cols);

    cout << rowMax * colMax;

    return 0;
}

int FindMax(vector<int>& v)
{
    int max = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i] - v[i - 1];
        if (temp > max)
        {
            max = temp;
        }
    }

    return max;
}
