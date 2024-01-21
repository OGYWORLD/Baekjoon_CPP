#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> A;
    vector<pair<int, int>> ACopy;
    int Number;

    for (int i = 0; i < N; i++)
    {
        cin >> Number;
        A.push_back(pair<int, int>(i, Number));
        ACopy.push_back(pair<int, int>(i, Number));
    }

    stable_sort(A.begin(), A.end(), compare);

    int Max = -500001;
    int IndexDif;
    for (int i = 0; i < N; i++)
    {
        IndexDif = A[i].first - ACopy[i].first;
        if (Max < IndexDif)
        {
            Max = IndexDif;
        }
    }

    Max++;
    cout << Max;

	return 0;
}

