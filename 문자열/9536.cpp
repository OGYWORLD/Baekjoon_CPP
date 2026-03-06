#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    int index = 0;
    string s;
    
    while (index < t)
    {
        int idx = 0;
        set<string> animalSet;
        vector<string> saying;
        while (true)
        {
            getline(cin, s);
            if (s.compare("what does the fox say?") == 0)
            {
                for (int i = 0; i < saying.size(); i++)
                {
                    if (animalSet.find(saying[i]) == animalSet.end())
                    {
                        cout << saying[i] << " ";
                    }
                }
                cout << "\n";
                index++;
                break;
            }
            else
            {
                if (idx == 0)
                {
                    stringstream ss(s);
                    string token;
                    while (getline(ss, token, ' '))
                    {
                        saying.push_back(token);
                    }
                }
                else
                {
                    stringstream ss(s);
                    string token;
                    vector<string> temp;
                    while (getline(ss, token, ' '))
                    {
                        temp.push_back(token);
                    }
                    animalSet.insert(temp[2]);
                }
                idx++;
            }
        }
    }

    return 0;
}
