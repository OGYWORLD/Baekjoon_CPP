#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a1;
    cin >> a1;

    vector<int> v;
    vector<int> resultVector;

    int max = -1;
    int a2 = a1;
    while (a2 != 0)
    {
        int head = a1, tail = a2;
        int cur;
        v.push_back(head);
        while (true)
        {
            cur = head - tail;
            v.push_back(tail);
            if (cur >= 0)
            {
                head = tail;
                tail = cur;
            }
            else
            {
                break;
            }
        }

        int size = v.size();
        if (size > max)
        {
            max = size;
            resultVector = v;
        }
        a2--;
        v.clear();
    }

    cout << max << "\n";
    for (int i = 0; i < resultVector.size(); i++)
    {
        cout << resultVector[i] << " ";
    }

    return 0;
}
