#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    
    int n, m;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int a, b;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
        }
        cout << n - 1 << "\n";
    }

    return 0;
}