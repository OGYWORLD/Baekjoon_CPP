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
    
    for(int i = 0; i < t; i++)
    {
        int n, watched;
        cin >> n;
        set<int> note1;
        for(int j = 0; j < n; j++)
        {
            cin >> watched;
            note1.insert(watched); 
        }
        
        int m, reQuestion;
        cin >> m;
        for(int j = 0; j < m; j++)
        {
             cin >> reQuestion;
             if(note1.find(reQuestion) != note1.end())
             {
                 cout << 1 << "\n";
             }
             else
             {
                 cout << 0 << "\n";
             }
        }
    }

    return 0;
}
