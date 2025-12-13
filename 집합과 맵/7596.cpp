#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int index = 1;
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        cin.ignore();

        set<string> musicSet;
        string s;
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            musicSet.insert(s);
        }

        cout << index << "\n";
        set<string>::iterator iter;
        for (iter = musicSet.begin(); iter != musicSet.end(); iter++)
        {
            cout << *iter << "\n";
        }

        index++;
    }

    return 0;
}
