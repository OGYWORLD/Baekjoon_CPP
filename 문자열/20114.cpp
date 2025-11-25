#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, h, w;
    cin >> n >> h >> w;

    vector<string> v(h);
    vector<char> answer(n, '?');
    string s;
    for (int i = 0; i < h; i++)
    {
        cin >> v[i];
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != '?')
            {
                answer[j / w] = v[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i];
    }

    return 0;
}