// 백준 14729 칠무해
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << fixed << setprecision(3);
    const int RIP_NUM = 7;
    for (int i = 0; i < RIP_NUM; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}

