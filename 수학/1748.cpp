#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = stoi(s);

    int len = s.size();
    int temp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        temp += 9 * pow(10, i);
    }

    int result = 0;
    while (n > 0)
    {
        result += (n - temp) * len;
        n -= (n - temp);

        temp = temp / 10;

        len--;
    }

    cout << result;

    return 0;
}