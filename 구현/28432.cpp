#include <iostream>
#include <vector>
#include <set>

using namespace std;

string FindBlank(vector<string>& v, bool& isFrontBack)
{
    string result = "";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].compare("?") == 0)
        {
            if (i - 1 >= 0)
            {
                result += v[i - 1][v[i - 1].size() - 1];
                isFrontBack = false;
            }
            if (i + 1 < v.size())
            {
                result += v[i + 1][0];
                isFrontBack = true;
            }
            break;
        }
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

    vector<string> v(n);
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }

    bool isFrontBack = false; // false Front, True Back
    string blank = FindBlank(v, isFrontBack);

    int m;
    cin >> m;

    string c;
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        if (s.find(c) == s.end())
        {
            int blankLen = blank.size();
            if (blankLen == 0)
            {
                cout << c;
                break;
            }
            else if (blankLen == 1)
            {
                if (isFrontBack)
                {
                    if (c[c.size() - 1] == blank[0])
                    {
                        cout << c;
                        break;
                    }
                }
                else
                {
                    if (c[0] == blank[0])
                    {
                        cout << c;
                        break;
                    }
                }
            }
            else if(blankLen == 2)
            {
                if (c[0] == blank[0] &&
                    c[c.size() - 1] == blank[1])
                {
                    cout << c;
                    break;
                }
            }
        }
    }

    return 0;
}