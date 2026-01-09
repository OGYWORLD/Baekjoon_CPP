#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        int r = a % b;
        return GCD(b, r);
    }
}

void GetAllGCDSum(vector<int>& v)
{
    long long result = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            result += GCD(v[i], v[j]);
        }
    }

    cout << result << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        GetAllGCDSum(v);
    }

    return 0;
}