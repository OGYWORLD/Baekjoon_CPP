#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string n1, n2;
    cin >> n1 >> n2;

    int n1Len = n1.size();
    int n2Len = n2.size();

    vector<int> v(n1Len + n2Len);
    int total = n1Len + n2Len - 2;
    int index = 1;

    int info[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
    for (int i = 0; i < n1Len + n2Len; i++)
    {
        if(i % 2 == 0) v[i] = info[n1[i / 2] - 'A'];
        else v[i] = info[n2[i / 2] - 'A'];
    }

    while (index <= total)
    {
        for (int i = 0; i < n1Len + n2Len - index; i++)
        {
            int temp = v[i] + v[i + 1];
            if (temp >= 10) v[i] = temp % 10;
            else v[i] = temp;
        }
        index++;
    }

    cout << v[0] << v[1];

    return 0;
}