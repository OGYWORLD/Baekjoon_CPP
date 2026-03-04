#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int result = 0;
    stack<char> origin;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            origin.push('(');
        }
        else
        {
            if (!origin.empty())
            {
                origin.pop();
            }
            else
            {
                result++;
            }
        }
    }

    cout << result + origin.size();

    return 0;
}
