#include <iostream>
#include <string>
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
    string result = s;

    for (int i = 1; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, j - i);
            string part3 = s.substr(j);

            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            reverse(part3.begin(), part3.end());

            string newString = part1 + part2 + part3;

            if (newString < result)
            {
                result = newString;
            }
        }
    }

    cout << result;

    return 0;
}