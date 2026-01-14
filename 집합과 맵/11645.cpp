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
        cin >> n;
        
        set<string> s;
        string city;
        for (int j = 0; j < n; j++)
        {
            cin >> city;
            s.insert(city);
        }
        cout << s.size() << "\n";
    }

    return 0;
}