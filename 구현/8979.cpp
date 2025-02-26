#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
    int index;
    int gold;
    int silver;
    int bronze;
};

bool Compare(const Info& a, const Info& b)
{
    if (a.gold == b.gold)
    {
        if (a.silver == b.silver)
        {
            return a.bronze > b.bronze;
        }
        else
        {
            return a.silver > b.silver;
        }
    }
    else
    {
        return a.gold > b.gold;
    }

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<Info> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].index;

        int g, s, b;
        cin >> g >> s >> b;
        v[i].gold = g;
        v[i].silver = s;
        v[i].bronze = b;
    }

    sort(v.begin(), v.end(), Compare);

    int targetInfo[] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        if (v[i].index == k)
        {
            targetInfo[0] = v[i].gold;
            targetInfo[1] = v[i].silver;
            targetInfo[2] = v[i].bronze;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i].gold == targetInfo[0] && v[i].silver == targetInfo[1] && v[i].bronze == targetInfo[2])
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}