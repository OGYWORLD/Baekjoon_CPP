#include <iostream>
#include <string>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int count = 0;
    int result = 0;
    int temp = 0;

    if (s.size() == 1)
    {
        result = s[0] - 48;
        if (result % 3 == 0) cout << "0\nYES";
        else cout << "0\nNO";

        return 0;
    }

    while (true)
    {
        for (int i = 0; i < s.size(); i++)
        {
            temp += s[i] - 48;
        }

        result = temp;
        temp = 0;
        count++;

        if (result < 10)
        {
            cout << count << "\n";
            if (result % 3 == 0) cout << "YES";
            else cout << "NO";

            break;
        }

        s = to_string(result);
    }

    return 0;
}
