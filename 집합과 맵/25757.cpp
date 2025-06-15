// 백준 25757 임스와 함께하는 미니게임
#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<char, int> m;
    m['Y'] = 1;
    m['F'] = 2;
    m['O'] = 3;

    char c;
    cin >> c;

    unordered_set <string> names;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        names.insert(s);
    }

    cout << names.size() / m[c];

    return 0;
}
