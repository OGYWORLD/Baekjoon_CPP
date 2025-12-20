#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    long long sum = 0;
    long long a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
    }

    cout << sum - (n * (n - 1) / 2);

    return 0;
}