#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string s, price;
    cin >> s >> price;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            s[i] = '9';
        }
    }

    if (s.length() > price.length())
    {
        cout << s;
    }
    else if (s.length() < price.length())
    {
        cout << -1;
    }
    else
    {
        if (s >= price)
        {
            cout << s;
        }
        else
        {
            cout << -1;
        }
    }

    return 0;
}