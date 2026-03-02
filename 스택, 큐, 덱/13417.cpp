#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    deque<char> d;
    int stringLen;
    for (int i = 0; i < n; i++)
    {
        cin >> stringLen;
        char c;
        cin >> c;
        d.push_back(c);
        for (int j = 1; j < stringLen; j++)
        {
            cin >> c;
            char front = d.front();
            if (c <= front)
            {
                d.push_front(c);
            }
            else
            {
                d.push_back(c);
            }
        }

        for (int i = 0; i < d.size(); i++)
        {
            cout << d[i];
        }
        d.clear();
        cout << "\n";
    }

    return 0;
}
