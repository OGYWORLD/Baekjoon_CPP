#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int low = 1;
    int high = 10;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        string a, b;
        cin >> a >> b;

        string s = a + " " + b;

        if (s == "too low")
        {
            low = max(low, n + 1);
        }
        else if (s == "too high")
        {
            high = min(high, n - 1);
        }
        else if (s == "right on")
        {
            if (low <= n && n <= high)
            {
                cout << "Stan may be honest\n";
            }
            else
            {
                cout << "Stan is dishonest\n";
            }

            low = 1;
            high = 10;
        }
    }

    return 0;
}
