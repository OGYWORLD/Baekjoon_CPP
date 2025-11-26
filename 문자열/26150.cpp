#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Puzzle
{
    string name;
    int index;
    int degree;
};

bool Compare(Puzzle& a, Puzzle& b)
{
    return a.index < b.index;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Puzzle> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].name >> v[i].index >> v[i].degree;
    }

    sort(v.begin(), v.end(), Compare);

    for (int i = 0; i < n; i++)
    {
        char c = v[i].name[v[i].degree - 1];
        if (c >= 'a') c -= ('a' - 'A');

        cout << c;
    }

    return 0;
}