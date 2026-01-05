#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long k;
    cin >> k;

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long left = a * k + b;
    long long right = c * k + d;

    if (left == right)
    {
        cout << "Yes " << left;
    }
    else
    {
        cout << "No";
    }

    return 0;
}