// 백준 2816 디지털 티비
#include <iostream>
#include <vector>

using namespace std;

void SWAP(string& a, string& b);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    string KBS[] = { "KBS1", "KBS2" };
    const int KBS_NUM = 2;
    int complete = 0;
    while (complete < KBS_NUM)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].compare(KBS[complete]) == 0)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << 1;
                }
                for (int j = 0; j < i - complete; j++)
                {
                    cout << 4;
                }

                for (int j = i; j > 0 + complete; j--)
                {
                    SWAP(v[j], v[j - 1]);
                }

                complete++;
            }
        }
    }

    return 0;
}

void SWAP(string& a, string& b)
{
    string temp = a;
    a = b;
    b = temp;
}
