#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int TOTAL_NUM = 91;
    vector<long long> dpTable(TOTAL_NUM);

    dpTable[0] = 0;
    dpTable[1] = 1;
    for (int i = 2; i < TOTAL_NUM; i++)
    {
        dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
    }

    int n;
    cin >> n;
    cout << dpTable[n];

    return 0;
}
