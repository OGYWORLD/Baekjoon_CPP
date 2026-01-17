#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int insaneRecordCnt = 0;
    unordered_set<int> recordSet;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        if (b == 1)
        {
            if (recordSet.find(a) != recordSet.end())
            {
                insaneRecordCnt++;
            }
            else
            {
                recordSet.insert(a);
            }
        }
        else
        {
            if (recordSet.find(a) != recordSet.end())
            {
                recordSet.erase(a);
            }
            else
            {
                insaneRecordCnt++;
            }
        }
    }

    cout << insaneRecordCnt + recordSet.size();

    return 0;
}