// 백준 14626 ISBN
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int N = 13;

    string s;
    cin >> s;

    int sum = 0;
    int missingCarry = 0;
    int carry = 1;
    for (int i = 0; i < N; i++)
    {
        int carry = (i % 2 == 0) ? 1 : 3;
        if (s[i] == '*')
        {
            missingCarry = carry;
        }
        else
        {
            sum += (s[i] - '0') * carry;
        }
    }

    for (int x = 0; x <= 9; x++)
    {
        if ((sum + x * missingCarry) % 10 == 0)
        {
            cout << x;
        }
    }

    return 0;
}
