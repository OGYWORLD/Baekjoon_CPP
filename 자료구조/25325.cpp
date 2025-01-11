#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<string, int> voteMap;
   
    string student;
    for (int i = 0; i < n; i++)
    {
        cin >> student;
        voteMap[student] = 0;
    }

    string con;
    while (cin >> con)
    {
        voteMap[con]++;
    }

    vector<pair<string, int>> list;
    map<string, int>::iterator iter;
    for (iter = voteMap.begin(); iter != voteMap.end(); iter++)
    {
        list.push_back(make_pair(iter->first, iter->second));
    }

    sort(list.begin(), list.end(), Compare);

    for (int i = 0; i < n; i++)
    {
        cout << list[i].first << " " << list[i].second << "\n";
    }

    return 0;
}