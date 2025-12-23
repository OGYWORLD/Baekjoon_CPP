#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ReverseString(string s)
{
    string result = "";
    for (int i = s.size() - 1; i > -1; i--)
    {
        result += s[i];
    }

    return result;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> v;

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(stoll(ReverseString(s)));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}