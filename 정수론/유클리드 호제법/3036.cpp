#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> rings(n);
    cin >> rings[0];
    for (int i = 1; i < n; i++)
    {
        cin >> rings[i];
        int g = GCD(rings[0], rings[i]);
        cout << rings[0] / g << "/" << rings[i] / g << "\n";
    }
    
    return 0;
}

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    int r = a % b;
    return GCD(b, r);
}
