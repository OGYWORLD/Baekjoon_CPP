#include <iostream>

using namespace std;

bool CheckSentence(string& s, string& t)
{
    int sLen = s.size();
    int index = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (index < sLen && s[index] == t[i])
        {
            index++;
        }
    }

    return index == sLen;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, t;
    while (cin >> s >> t)
    {
        if (CheckSentence(s, t))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}