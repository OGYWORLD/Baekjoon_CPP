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

    map<long long, int> m;
    long long card;
    for (int i = 0; i < n; i++)
    {
        cin >> card;

        if (m.find(card) == m.end())
        {
            m[card] = 1;
        }
        else
        {
            m[card] += 1;
        }
    }

    int max = -1;
    long long result;
    map<long long, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        long long cnd = iter->first;
        int n = iter->second;

        if (n > max)
        {
            max = n;
            result = cnd;
        }
    }

    cout << result;

    return 0;
}