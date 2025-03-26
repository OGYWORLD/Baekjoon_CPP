#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, n;

    cin >> a >> b >> n;

    int r = a % b;
    int index = 1;
    while (index < n)
    {
        r = (r * 10) % b;

        index++;
    }

    cout << (r * 10) / b;

    return 0;
}
