#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<long long, int> cntMap;
    int t;
    long long soldier;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> soldier;
            cntMap[soldier]++;
        }

        int maxCnt = 0;
        long long maxIndex = 0;
        map<long long, int>::iterator iter;
        for (iter = cntMap.begin(); iter != cntMap.end(); iter++)
        {
            if (iter->second > maxCnt)
            {
                maxCnt = iter->second;
                maxIndex = iter->first;
            }
        }

        if(maxCnt > t / 2)
        {
            cout << maxIndex << "\n";
        }
        else
        {
            cout << "SYJKGW\n";
        }

        cntMap.clear();
    }

    return 0;
}
