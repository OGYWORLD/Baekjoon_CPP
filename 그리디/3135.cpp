#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int min = abs(a - b);

    int n;
    cin >> n;

    bool isUseShortcutBtn = false;
    int btn;
    for (int i = 0; i < n; i++)
    {
        cin >> btn;

        int temp = abs(btn - b);
        if (min > temp)
        {
            isUseShortcutBtn = true;
            min = temp;
        }
    }

    if (isUseShortcutBtn)
    {
        cout << min + 1;
    }
    else
    {
        cout << min;
    }


    return 0;
}
