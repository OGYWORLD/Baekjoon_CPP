// 백준 6888 Terms of Office
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    for (int i = 0; x + i <= y; i += 60)
    {
        cout << "All positions change in year " << x + i << "\n";
    }

    return 0;
}

