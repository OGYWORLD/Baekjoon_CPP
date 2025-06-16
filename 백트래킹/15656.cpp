// 백준 15656 N과 M(7)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> seq;

void BackTracking(int depth);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    nums.resize(n);
    seq.resize(m);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    BackTracking(0);

    return 0;
}

void BackTracking(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << seq[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        seq[depth] = nums[i];
        BackTracking(depth + 1);
    }
}
