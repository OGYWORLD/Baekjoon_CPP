#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int stick[] = { 64, 32, 16, 8, 4, 2, 1 };

    int result = 0;
    for (int i = 0; i < 7; i++)
    {
        if (n >= stick[i])
        {
            result++;
            n -= stick[i];
        }

        if (n <= 0) break;
    }

    cout << result;

    return 0;
}