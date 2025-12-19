#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int CARD = 5;

    int n;
    cin >> n;

    int index = 1;
    int maxIdx = -1;
    int max = -1;
    while(index <= n)
    {
        vector<int> v(CARD);
        for (int i = 0; i < CARD; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < CARD; i++)
        {
            for (int j = i + 1; j < CARD; j++)
            {
                for (int k = j + 1; k < CARD; k++)
                {
                    int mod = (v[i] + v[j] + v[k]) % 10;
                    if (max <= mod)
                    {
                        max = mod;
                        maxIdx = index;
                    }
                }
            }
        }

        index++;
    }

    cout << maxIdx;

    return 0;
}