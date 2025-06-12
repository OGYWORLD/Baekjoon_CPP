// 백준 1817 짐 챙기는 숌
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int temp = 0;
    int result = 0;
    int w;
    for (int i = 0; i < n; i++)
    {
        cin >> w;

        if (temp + w > m)
        {
            result++;
            temp = w;
        }
        else if (temp + w == m)
        {
            result++;
            temp = 0;
        }
        else
        {
            temp += w;
        }
    }

    if (temp > 0)
    {
        result++;
    }

    cout << result;

    return 0;
}
