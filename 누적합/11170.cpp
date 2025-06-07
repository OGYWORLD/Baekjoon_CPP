// 백준 11170 0의 개수
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int zeroNum = 0;
    vector<int> v(1000001, 0);
    for (int i = 0; i <= 1000000; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '0') zeroNum++;
        }
        v[i] = zeroNum;
    }

    int t;
    cin >> t;
    int n, m;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        cout << v[m] - (n - 1 > -1 ? v[n - 1] : 0) << "\n";
    }

    return 0;
}
