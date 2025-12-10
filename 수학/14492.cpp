#include <iostream>
#include <vector>

using namespace std;

void GetMatrix(vector<vector<int>>& v, int n);
void CalculateAndPrint(vector<vector<int>>& a, vector<vector<int>>& b, int n);


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> a;
    vector<vector<int>> b;

    GetMatrix(a, n);
    GetMatrix(b, n);

    CalculateAndPrint(a, b, n);

    return 0;
}

void GetMatrix(vector<vector<int>>& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            cin >> temp[j];
        }
        v.push_back(temp);
    }
}

void CalculateAndPrint(vector<vector<int>>& a, vector<vector<int>>& b, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((a[i][k] && b[k][j]) == 1)
                {
                    result++;
                    break;
                }
            }
        }
    }

    cout << result;
}
