#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<string, string> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        m[s1] = s3;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        string s;
        for (int j = 0; j < n; j++)
        {
            cin >> s;
            cout << m[s] << " ";
        }
        cout << "\n";
    }

    return 0;
}
