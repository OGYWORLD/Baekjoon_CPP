#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<string, int> extensionCount;
    string file;
    for (int i = 0; i < n; i++)
    {
        cin >> file;
        string extension = "";
        for (int j = 0; j < file.size(); j++)
        {
            if (file[j] == '.')
            {
                extension = file.substr(j + 1);
            }
        }
        extensionCount[extension]++;
    }

    map<string, int>::iterator iter;
    for (iter = extensionCount.begin(); iter != extensionCount.end(); iter++)
    {
        cout << iter->first << " " << iter->second << "\n";
    }

    return 0;
}
