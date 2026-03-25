#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<long long> totalSum(n);
    for (int i = 0; i < n; i++)
    {
        int people;
        cin >> people;
        long long time;
        long long sum = 0;
        for (int j = 0; j < people; j++)
        {
            cin >> time;
            sum += time;
        }
        totalSum[i] = sum;
    }

    sort(totalSum.begin(), totalSum.end());

    long long result = totalSum[0];
    for (int i = 1; i < n; i++)
    {
        totalSum[i] = totalSum[i - 1] + totalSum[i];
        result += totalSum[i];
    }

    cout << result;

    return 0;
}