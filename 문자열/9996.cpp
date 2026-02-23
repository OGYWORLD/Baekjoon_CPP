#include <iostream>

using namespace std;

bool isMatch(const string& pattern, const string& files);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    string files;
    for (int i = 0; i < n; i++)
    {
        cin >> files;
        if (isMatch(pattern, files))
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }

    return 0;
}

bool isMatch(const string& pattern, const string& s)
{
    int star = pattern.find('*');
    string prefix = pattern.substr(0, star);
    string suffix = pattern.substr(star + 1);

    if (s.size() < prefix.size() + suffix.size())
    {
        return false;
    }

    if (s.compare(0, prefix.size(), prefix) != 0)
    {
        return false;
    }

    if (s.compare(s.size() - suffix.size(), suffix.size(), suffix) != 0)
    {
        return false;
    }

    return true;
}