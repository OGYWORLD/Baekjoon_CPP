#include <iostream>
#include <string>

using namespace std;

long long GetWeiredMultiple(long long a, long long b);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    long long a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

        if (a * b == GetWeiredMultiple(a, b))
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

long long GetWeiredMultiple(long long a, long long b)
{
    string s = "";
    string s_a = to_string(a);
    string s_b = to_string(b);

    int lenA = s_a.size();
    int lenB = s_b.size();
    int minLen = min(lenA, lenB);

    if (lenA > lenB)
    {
        for (int i = 0; i < lenA - lenB; i++)
        {
            s += s_a[i];
        }
    }
    else if (lenB > lenA)
    {
        for (int i = 0; i < lenB - lenA; i++)
        {
            s += s_b[i];
        }
    }

    int startA = lenA - minLen;
    int startB = lenB - minLen;

    for (int i = 0; i < minLen; i++)
    {
        long long m = (s_a[startA + i] - '0') * (s_b[startB + i] - '0');
        s += to_string(m);
    }

    return stoll(s);
}
