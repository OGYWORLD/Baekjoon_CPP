#include <iostream>
#include <map>
#include <stack>

using namespace std;

double Calculation(double a1, double a2, char c);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<char, double> m;
    stack<double> stck;

    string s;
    cin >> s;
    double a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m[i + 'A'] = a;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 'A')
        {
            double a1 = stck.top();
            stck.pop();
            double a2 = stck.top();
            stck.pop();
            stck.push(Calculation(a2, a1, s[i]));
        }
        else
        {
            stck.push(m[s[i]]);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << stck.top();

    return 0;
}

double Calculation(double a1, double a2, char c)
{
    double result = 0;
    switch (c)
    {
    case '+':
        result = a1 + a2;
        break;
    case '-':
        result = a1 - a2;
        break;
    case '*':
        result = a1 * a2;
        break;
    case '/':
        result = a1 / a2;
        break;
    }
    return result;
}
