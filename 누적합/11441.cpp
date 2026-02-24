#include <iostream>
#include <vector>

using namespace std;

int ConvertValue(const vector<int>& totalSum, int idx);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a;
    vector<int> totalSum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i == 0)
        {
            totalSum[i] = a;
        }
        else
        {
            totalSum[i] = a + totalSum[i - 1];
        }
    }

    int m;
    cin >> m;
    int ai, aj;
    for (int i = 0; i < m; i++)
    {
        cin >> ai >> aj;
        cout << ConvertValue(totalSum, aj - 1) - ConvertValue(totalSum, ai- 2) << "\n";
    }

    return 0;
}

int ConvertValue(const vector<int>& totalSum, int idx)
{
    if (idx < 0)
    {
        return 0;
    }

    return totalSum[idx];
}
