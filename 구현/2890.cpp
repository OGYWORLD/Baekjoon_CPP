#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct info
{
    int number;
    int dotNum;
};

bool Compare(info& a, info& b)
{
    return a.number < b.number;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    const int BOAT = 9;
 
    vector<info> v(BOAT);
    map<int, int> dotRank;

    int idx = 0;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        int dotNum = 0;
        bool isExist = false;
        int num;
        for (int j = 0; j < c - 1; j++)
        {
            if (s[j] == 'S')
            {
                continue;
            }
            else if (s[j] == '.')
            {
                dotNum++;
            }
            else
            {
                num = s[j] - '0';
                isExist = true;
                break;
            }
        }
        if (isExist)
        {
            int leftDotNum = c - dotNum - 5;
            v[idx].dotNum = leftDotNum;
            dotRank[leftDotNum] = 0;
            v[idx].number = num;
            idx++;
        }
    }

    map<int, int>::iterator iter;
    int index = 1;
    for (iter = dotRank.begin(); iter != dotRank.end(); iter++, index++)
    {
        dotRank[iter->first] = index;
    }

    sort(v.begin(), v.end(), Compare);

    for (int i = 0; i < BOAT; i++)
    {
        cout << dotRank[v[i].dotNum] << "\n";
    }

    return 0;
}
