#include <iostream>

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

int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

void CheckSameSentence(const string& s, const string& t)
{
    int sLen = s.size();
    int tLen = t.size();
    int l = LCM(sLen, tLen);
    for (int i = 0; i < l; i++)
    {
        if (s[i % sLen] != t[i % tLen])
        {
            cout << 0;
            return;
        }
    }

    cout << 1;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int sLen = s.size();
    int tLen = t.size();

    CheckSameSentence(t, s);

    return 0;
}