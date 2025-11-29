#include <iostream>
#include <vector>

using namespace std;

struct Info
{
    string name;
    vector<char> letter;
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int index = 1;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0) break;

        cout << "Group " << index << "\n";

        vector<Info> v(n);
        string name;
        char letter;
        bool isExist = false;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
            v[i].name = name;
            vector<char> temp;
            for (int j = 0; j < n - 1; j++)
            {
                cin >> letter;
                if (letter == 'N') isExist = true;
                temp.push_back(letter);
            }
            v[i].letter = temp;
        }

        if (isExist)
        {
            for (int i = 0; i < n; i++)
            {
                vector<char> &curLetter = v[i].letter;
                for (int j = 0; j < n - 1; j++)
                {
                    if (curLetter[j] == 'N')
                    {
                        cout << v[(n + (i - (j + 1))) % n].name << " was nasty about " << v[i].name << "\n";
                    }
                }
            }
        }
        else
        {
            cout << "Nobody was nasty\n";
        }
        cout << "\n";
        index++;
    }

    return 0;
}