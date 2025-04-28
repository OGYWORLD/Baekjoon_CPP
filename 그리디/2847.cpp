#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int result = 0;
    for (int i = n - 2; i > -1; i--)
    {
        if (v[i + 1] <= v[i])
        {
            result += v[i] - v[i + 1] + 1;
            v[i] = v[i + 1] - 1;
        }
    }

    cout << result;

    return 0;
}
