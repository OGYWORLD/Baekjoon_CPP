#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string title;
    getline(cin, title);

    vector<char> candidate;
    for (int i = 0; i < title.size(); i++)
    {
        if (title[i] != ' ' && title[i] < 97)
        {
            candidate.push_back(title[i]);
        }
    }

    string UCPC = "UCPC";
    int index = 0;
    for (int i = 0; i < candidate.size(); i++)
    {
        if (candidate[i] == UCPC[index])
        {
            index++;
        }
    }

    if (index == UCPC.size())
    {
        cout << "I love UCPC";
    }
    else
    {
        cout << "I hate UCPC";
    }


    return 0;
}