#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        n = (n - 1) % 28 + 1;

        if (n > 15)
        {
            n = 30 - n;
        }

        string temp = bitset<4>(n).to_string();
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '0')
            {
                cout << 'V';
            }
            else
            {
                cout << "딸기";
            }
        }
        cout << "\n";
    }

    return 0;
}