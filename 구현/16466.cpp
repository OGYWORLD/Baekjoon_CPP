// 백준 16466 콘서트 - 2025 에픽하이 콘서트 첫콘 갔다온 날 기념~!

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int TICKET = 1000001;
    vector<bool> v(TICKET, true);

    int n;
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v[a] = false;
    }

    for (int i = 1; i < TICKET; i++)
    {
        if (v[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}