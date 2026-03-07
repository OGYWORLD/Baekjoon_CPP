#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    int e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> e;
            if (q.size() < n)
            {
                q.push(e);
            }
            else
            {
                if (e > q.top())
                {
                    q.pop();
                    q.push(e);
                }
            }
        }
    }

    cout << q.top();

    return 0;
}
