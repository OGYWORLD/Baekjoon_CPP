#include <iostream>
#include <map>
#include <set>

using namespace std;

enum Category
{
    NameList,
    GroupName,
    Max
};

void PrintName(const set<string>& s)
{
    set<string>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++)
    {
        cout << *iter << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<string, set<string>> groupToNameMap;
    map<string, string> nameToGroupMap;
    string group;
    int groupNum;
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> group >> groupNum;
        set<string> v;
        for (int j = 0; j < groupNum; j++)
        {
            cin >> name;
            v.insert(name);
            nameToGroupMap[name] = group;
        }
        groupToNameMap[group] = v;
    }

    int category;
    for (int i = 0; i < m; i++)
    {
        cin >> name >> category;
        switch (category)
        {
        case Category::GroupName:
            cout << nameToGroupMap[name] << "\n";
            break;
        case Category::NameList:
            PrintName(groupToNameMap[name]);
        }
    }

    return 0;
}
