#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    string s;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(91, 0);

        getline(cin, s);

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                continue;
            }

            if (s[j] > 'Z')
            {
                v[s[j] - ('a' - 'A')]++;
            }
            else
            {
                v[s[j]]++;
            }
        }

        int min = 999999999;
        for (int j = 'A'; j <= 'Z'; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
            }
        }

        if (min == 0)
        {
            cout << "Case " << i + 1 << ": Not a pangram\n";
        }
        else if (min == 1)
        {
            cout << "Case " << i + 1 << ": Pangram!\n";
        }
        else if (min == 2)
        {
            cout << "Case " << i + 1 << ": Double pangram!!\n";
        }
        else if (min == 3)
        {
            cout << "Case " << i + 1 << ": Triple pangram!!!\n";
        }
    }

    return 0;
}