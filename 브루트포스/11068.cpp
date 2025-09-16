#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string GetNBase(int value, int base);
bool IsPalindrome(int value);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (IsPalindrome(v))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }


    return 0;
}

string GetNBase(int value, int base)
{
    const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

    if(value == 0)
    {
        return "0";
    }

    string result;
    while (value > 0)
    {
        int remainder = value % base;
        result.push_back(digits[remainder]);
        value /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool IsPalindrome(int value)
{
    const int MAX_BASE = 64;
    for (int i = 2; i <= MAX_BASE; i++)
    {
        string temp = GetNBase(value, i);
        int len = temp.size();
        bool isPalindrome = true;
        for (int j = 0; j < len / 2; j++)
        {
            if (temp[j] != temp[len - j - 1])
            {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome)
        {
            return true;
            break;
        }
    }

    return false;
}
