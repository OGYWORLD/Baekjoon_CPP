#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cnt[10] = { 0 };
    int diff = 0;

    int srt = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt[v[i]] == 0)
        {
            diff++;
        }
        cnt[v[i]]++;

        while (diff > 2)
        {
            cnt[v[srt]]--;
            if (cnt[v[srt]] == 0)
            {
                diff--;
            }
            srt++;
        }

        int len = i - srt + 1;
        if (len > end)
        {
            end = len;
        }
    }

    cout << end;
    return 0;
}