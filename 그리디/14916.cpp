#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a = 0, b = 0;
    int target = 0;
    bool flag = false;
    while (a >= 0 && b >= 0)
    {
        target = 2 * a + 5 * b;
        if (target == n) break;
        else if (target < n && !flag)
        {
            b++;
        }
        else if (target < n && flag)
        {
            a++;
            flag = false;
        }
        else if (target > n)
        {
            flag = true;
            b--;
            a++;
        }

    }

    if (a < 0 || b < 0)
    {
        cout << -1;
    }
    else
    {
        cout << a + b;
    }


    return 0;
}