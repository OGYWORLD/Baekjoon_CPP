#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n, m;
    cin >> n >> m;

    if (n >= m)
    {
        cout << 0;
        return 0;
    }

    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i % m;
    }

    cout << result;

    return 0;
}