#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    unordered_map<int, int> cntMap;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cntMap[x]++;
    }

    int answer = 0;
    unordered_map<int, int>::iterator iter;
    for (iter = cntMap.begin(); iter != cntMap.end(); iter++)
    {
        answer += min(iter->second, 2);
    }

    cout << answer << "\n";

    return 0;
}