#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int len = s.size();
    unordered_set<int> zeroIdxSet;
    bool isPossible = false;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += s[i] - '0';
        if (s[i] == '0')
        {
            isPossible = true;
            zeroIdxSet.insert(i);
        }
    }

    if (sum % 3 != 0) isPossible = false;

    if (!isPossible) cout << -1;
    else
    {
        vector<int> numbers;
        for (int i = 0; i < len; i++)
        {
            if (zeroIdxSet.find(i) == zeroIdxSet.end())
            {
                numbers.push_back(s[i] - '0');
            }
        }

        sort(numbers.begin(), numbers.end());

        for (int i = numbers.size() - 1; i > -1; i--)
        {
            cout << numbers[i];
        }
        for (int i = 0; i < zeroIdxSet.size(); i++)
        {
            cout << 0;
        }
    }


    return 0;
}
