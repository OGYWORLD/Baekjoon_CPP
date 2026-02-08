#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const pair<string, string>& a, const pair<string, string>& b);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), Compare);

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}

bool Compare(const pair<string, string>& a, const pair<string, string>& b)
{
    if (a.first.compare(b.first) == 0)
    {
        return a.second > b.second;
    }
    
    return a.first < b.first;
}
