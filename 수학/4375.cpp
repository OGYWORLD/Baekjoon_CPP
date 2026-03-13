#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n)
    {
        int r = 1 % n;
        int len = 1;

        while (r != 0)
        {
            r = (r * 10 + 1) % n;
            len++;
        }

        cout << len << "\n";
    }

    return 0;
}