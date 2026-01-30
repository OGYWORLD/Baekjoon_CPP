#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int m;
    cin >> m;

    string s;
    cin >> s;

    int cnt = 0;
    int io = 0;
    for (int i = 1; i < m - 1; i++)
    {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
        {
            io++;
            if (io >= n) cnt++;
            i++;
        }
        else io = 0;
    }

    cout << cnt;

    return 0;
}