#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int j;
    cin >> j;

    vector<int> apples(j);
    for (int i = 0; i < j; i++)
    {
        cin >> apples[i];
    }

    int head = 1;
    int cnt = 0;
    for (int i = 0; i < j; i++)
    {
        if (head + m - 1 < apples[i])
        {
            cnt += apples[i] - (head + m - 1);
            head = apples[i] - m + 1;
        }
        else if (head > apples[i])
        {
            cnt += head - apples[i];
            head = apples[i];
        }
    }

    cout << cnt;


    return 0;
}
