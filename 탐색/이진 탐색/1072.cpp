#include <iostream>

using namespace std;

long long GetPercent(double y, double x, int mid);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long x, y;
    cin >> x >> y;

    long long originZ = (y * 100 )/ x;

    if (originZ >= 99)
    {
        cout << -1;
        return 0;
    }

    long long left = 1;
    long long right = 1000000000;
    long long answer = -1;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long newZ = GetPercent(y, x, mid);

        if (newZ > originZ)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}

long long GetPercent(double y, double x, int mid)
{
    return (((y + mid) * 100) / (x + mid));
}
