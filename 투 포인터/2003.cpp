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

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int start = 0;
    int end = 0;

    int target = v[0];
    int result = 0;
    for (; end < n;)
    {
        if (target == m)
        {
            result++;

            target -= v[start];
            start++;

            if (start >= n)
            {
                break;
            }

            if (start > end)
            {
                end = start;
                target = v[start];
            }
        }
        else if(target < m)
        {
            end++;
            if (end >= n)
            {
                break;
            }
            target += v[end];
        }
        else if (target > m)
        {
            target -= v[start];
            start++;
        }
    }

    cout << result;

    return 0;
}
