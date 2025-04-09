#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAX = 1001;
    vector<bool> dpTable(MAX);

    int n;
    cin >> n;

    dpTable[1] = true;
    dpTable[2] = false;
    dpTable[3] = true;
    dpTable[4] = true;

    for (int i = 5; i < MAX; i++)
    {
        dpTable[i] = !dpTable[i - 1] || !dpTable[i - 3] || !dpTable[i - 4];
    }

    if (dpTable[n])
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }

    return 0;
}
