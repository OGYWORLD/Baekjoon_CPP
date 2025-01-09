#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long s;
    cin >> s;

    long long temp = (long long)sqrt(s * 2);

    long long standard = temp * (temp + 1) / 2;

    while (standard > s)
    {
        temp--;
        standard = temp * (temp + 1) / 2;
    }

    cout << temp;

    return 0;
}