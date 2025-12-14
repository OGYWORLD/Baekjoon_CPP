#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int minCost = v[0];
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        result = max(result, v[i] - minCost);
        minCost = min(minCost, v[i]);
    }

    cout << result;

    return 0;
}
