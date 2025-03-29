#include <iostream>
#include <queue>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> q;

    int index = 0;
    int dasom = 0;
    cin >> dasom;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    int c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> c;
        q.push(c);
    }

    int buying = 0;
    while (true)
    {
        if (dasom > q.top())
        {
            cout << buying;
            break;
        }

        if(dasom <= q.top())
        {
            int t = q.top();
            q.pop();
            t--;
            q.push(t);
            dasom++;
            buying++;
        }
    }

    return 0;
}
