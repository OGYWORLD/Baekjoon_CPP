#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> dpTableA(47, 0);
    vector<int> dpTableB(47, 0);

    dpTableA[1] = 1;
    dpTableB[2] = 1;

    for (int i = 3; i <= 46; i++)
    {
        dpTableA[i] = dpTableA[i - 1] + dpTableA[i - 2];
        dpTableB[i] = dpTableB[i - 1] + dpTableB[i - 2];
    }

    int k;
    cin >> k;

    cout << dpTableA[k+1] << " " << dpTableB[k+1];

    return 0;
}
