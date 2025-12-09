#include <iostream>
#include <string>

using namespace std;

bool CheckSameNumber(int n);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;

    while (cin >> a >> b)
    {
        int result = 0;
        for (int i = a; i <= b; i++)
        {
            if (!CheckSameNumber(i))
            {
                result++;
            }
        }

        cout << result << "\n";
    }

    return 0;
}

bool CheckSameNumber(int n)
{
    bool isExist[] = { false, false,  false,  false,  false,  false,  false,  false,  false,  false};
    string s = to_string(n);

    bool isSame = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isExist[s[i] - '0'])
        {
            isExist[s[i] - '0'] = true;
        }
        else
        {
            isSame = true;
            break;
        }
    }

    return isSame;
}
