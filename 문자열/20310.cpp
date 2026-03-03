#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int zeroNum = 0;
    int oneNum = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            oneNum++;
        }
        else
        {
            zeroNum++;
        }
    }

    zeroNum /= 2;
    oneNum /= 2;

    const char MASK_CHAR = '9';
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            if (oneNum != 0)
            {
                s[i] = MASK_CHAR;
                oneNum--;
            }
        }
    }

    for (int i = len - 1; i > -1; i--)
    {
        if (s[i] == '0')
        {
            if (zeroNum != 0)
            {
                s[i] = MASK_CHAR;
                zeroNum--;
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] != MASK_CHAR)
        {
            cout << s[i];
        }
    }

    return 0;
}
