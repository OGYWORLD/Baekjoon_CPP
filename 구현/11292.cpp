#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ConvertStringToInt(string s);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<pair<string, int>> heightList;

    int n;
    while (true)
    {
        cin >> n;

        if (n == 0) break;

        int max = -1;
        string name, height;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> height;

            int h = ConvertStringToInt(height);
            heightList.push_back(make_pair(name, h));

            if (h > max) max = h;
        }

        for (int i = 0; i < heightList.size(); i++)
        {
            if (heightList[i].second == max) cout << heightList[i].first << " ";
        }
        cout << "\n";
        heightList.clear();
    }

    return 0;
}

int ConvertStringToInt(string s)
{
    int len = s.size();
    int height = 0;
    height += (s[len - 2] - '0') * 10;
    height += s[len - 1] - '0';

    for (int i = len - 4; i > -1; i--)
    {
        height += (s[i] - '0') * (pow(10, len - 2 - i));
    }

    return height;
}
