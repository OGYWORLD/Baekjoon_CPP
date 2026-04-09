#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << "NO";
        return 0;
    }

    vector<long long> v;
    long long f = 1;
    int i = 0;

    while (f <= n)
    {
        v.push_back(f);
        i++;
        f *= i;
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] <= n)
        {
            n -= v[i];
        }
    }

    if (n == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}