#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int TOTAL_SIZE = 4;

    set<string> result;
    vector<string> color(TOTAL_SIZE);
    cin >> color[0] >> color[1] >> color[2] >> color[3];

    for (int i = 0; i < TOTAL_SIZE; i++)
    {
        for (int j = 0; j < TOTAL_SIZE; j++)
        {
            result.insert(color[i] + " " + color[j]);
        }
    }

    set<string>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << "\n";
    }

    return 0;
}