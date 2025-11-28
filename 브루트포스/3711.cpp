#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n;
    unordered_set<int> checkSet;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        for (int j = 1; ; j++)
        {
            checkSet.clear();

            bool isAnswer = true;
            for (int k = 0; k < n; k++)
            {
                int mod = v[k] % j;
                if (checkSet.find(mod) != checkSet.end())
                {
                    isAnswer = false;
                    break;
                }
                else
                {
                    checkSet.insert(mod);
                }
            }
            if (isAnswer)
            {
                cout << j << "\n";
                break;
            }
        }
    }

    return 0;
}