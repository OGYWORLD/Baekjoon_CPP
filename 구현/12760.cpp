#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<priority_queue<int>> cards(n);
    for (int i = 0; i < n; i++)
    {
        int card;
        for (int j = 0; j < m; j++)
        {
            cin >> card;
            cards[i].push(card);
        }
    }

    vector<pair<int, int>> score(n);
    for (int i = 0; i < n; i++)
    {
        score[i].first = 0;
        score[i].second = i + 1;
    }

    int index = 0;
    while (index < m)
    {
        int roundMax = -1;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            int top = cards[i].top();
            cards[i].pop();

            temp[i] = top;

            if (roundMax < top) roundMax = top;
        }

        for (int i = 0; i < n; i++)
        {
            if (temp[i] == roundMax)
            {
                score[i].first++;
            }
        }

        index++;
    }

    sort(score.begin(), score.end(), Compare);

    for (int i = 0; i < n; i++)
    {
        if (score[0].first == score[i].first)
        {
            cout << score[i].second << " ";
        }
    }

    return 0;
}

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
