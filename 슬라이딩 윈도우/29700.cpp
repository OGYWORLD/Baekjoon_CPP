#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int countZero = 0;
        string chair;
        cin >> chair;
        for (int j = 0; j < m; j++)
        {
            if (chair[j] == '0')
            {
                countZero++;
            }
            else
            {
                countZero = 0;
            }

            if (countZero == k)
            {
                result++;
                countZero--;
            }
        }
    }

    cout << result;

    return 0;
}