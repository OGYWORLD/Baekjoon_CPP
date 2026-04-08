#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, int> m;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        m[a]++;
    }

    map<int, int>::iterator iter;

    int max = -1;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (max < iter->second)
        {
            max = iter->second;
        }
    }

    cout << max;

    return 0;
}