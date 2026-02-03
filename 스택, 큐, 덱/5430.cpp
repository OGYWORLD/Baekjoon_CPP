#include <iostream>
#include <deque>
#include <string>

using namespace std;

void ParsingNumber(string s, deque<int>& v);
void CalculateD(deque<int>& v, bool isReverse);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int index = 0;
    while (index < t)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string json;
        cin >> json;

        deque<int> numbers;
        ParsingNumber(json, numbers);

        bool isReverse = false;
        bool isError = false;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else if (p[i] == 'D')
            {
                if (numbers.size() == 0)
                {
                    isError = true;
                    break;
                }
                CalculateD(numbers, isReverse);
            }
        }
        
        if (isError)
        {
            cout << "error\n";
        }
        else
        {
            int len = numbers.size();
            cout << "[";
            if (!isReverse)
            {
                for (int i = 0; i < len; i++)
                {
                    if (i != len - 1)
                    {
                        cout << numbers[i] << ",";
                    }
                    else
                    {
                        cout << numbers[i];
                    }
                }
                cout << "]\n";
            }
            else
            {
                for (int i = len - 1; i > -1; i--)
                {
                    if (i != 0)
                    {
                        cout << numbers[i] << ",";
                    }
                    else
                    {
                        cout << numbers[i];
                    }
                }
                cout << "]\n";
            }
        }

        index++;
    }



    return 0;
}

void ParsingNumber(string s, deque<int>& v)
{
    int num = 0;
    bool inNum = false;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + (c - '0');
            inNum = true;
        }
        else
        {
            if (inNum)
            {
                v.push_back(num);
                num = 0;
                inNum = false;
            }
        }
    }
}

void CalculateD(deque<int>& v, bool isReverse)
{
    if (isReverse)
    {
        v.pop_back();
    }
    else
    {
        v.pop_front();
    }
}
