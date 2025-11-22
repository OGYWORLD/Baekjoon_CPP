#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int n;
    while (cin >> n)
    {
        if (n == 1)
        {
            int dump;
            for (int i = 0; i < n; i++)
            {
                cin >> dump;
            }
            cout << "Jolly\n";
            continue;
        }

        int j;
        for (int i = 0; i < n; i++)
        {
            cin >> j;
            v.push_back(j);
        }

        vector<bool> diff(n, false);
        bool isJollyJumper = true;
        for (int i = 0; i < n - 1; i++)
        {
            int difN = abs(v[i] - v[i + 1]);
            if (difN > n - 1)
            {
                isJollyJumper = false;
                break;
            }
            diff[difN] = true;
        }

        if (isJollyJumper)
        {
            for (int i = 1; i < n; i++)
            {
                if (!diff[i])
                {
                    isJollyJumper = false;
                    break;
                }
            }
        }

        if (isJollyJumper) cout << "Jolly\n";
        else cout << "Not jolly\n";

        v.clear();
        diff.clear();
    }

    return 0;
}