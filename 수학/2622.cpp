#include <iostream>

using namespace std;

bool CheckCanBeTriangle(int a, int b, int c);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= (n - i); j++)
        {
            int k = n - i - j;
            if (k < j || k <= 0)
            {
                continue;
            }

            if (CheckCanBeTriangle(i, j, k))
            {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}

bool CheckCanBeTriangle(int a, int b, int c)
{
    return a + b > c;
}
