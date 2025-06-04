// 백준 1120 문자열
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    int aLen = a.size();
    int bLen = b.size();

    int min = 999999999;
    for (int i = 0; i <= bLen - aLen; i++)
    {
        int dif = 0;
        for (int j = 0; j < aLen; j++)
        {
            if (a[j] != b[i + j]) dif++;
        }

        if (dif < min) min = dif;
    }

    cout << min;

    return 0;
}
