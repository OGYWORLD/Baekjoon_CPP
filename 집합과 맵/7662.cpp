#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        multiset<int> m;
        cin >> n;
        
        char c;
        int entity;
        for (int j = 0; j < n; j++)
        {
            cin >> c >> entity;

            if (c == 'I')
            {
                m.insert(entity);
            }
            else if (!m.empty() && c == 'D')
            {
                if (entity == 1)
                {
                    m.erase(prev(m.end()));
                }
                else
                {
                    m.erase(m.begin());
                }
            }
        }

        if (m.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            auto it = prev(m.end());
            cout << *it << " ";
           
            it = m.begin();
            cout << *it << "\n";
        }
    }

    return 0;
}