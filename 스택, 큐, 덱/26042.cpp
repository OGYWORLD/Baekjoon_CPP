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

    int maxSize = -1;
    int lastPerson = 0;
    queue<int> q;
    int a;
    int person;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> person;
            q.push(person);

            int qSize = q.size();
            int qBack = q.back();
            if (qSize > maxSize)
            {
                maxSize = qSize;
                lastPerson = qBack;
            }
            else if (qSize == maxSize)
            {
                if (lastPerson > qBack)
                {
                    lastPerson = qBack;
                }
            }
        }
        else if (a == 2)
        {
            q.pop();
        }
    }

    cout << maxSize << " " << lastPerson;

    return 0;
}