#include <iostream>

using namespace std;

void LCM(long long a, long long b, long long originA, long long originB)
{
    if (b == 0)
    {
        cout << originA / a * originB << "\n";
        return;
    }

    int r = a % b;
    LCM(b, r, originA, originB);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        LCM(a, b, a, b);
    }

    return 0;
}