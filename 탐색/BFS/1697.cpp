#include <iostream>
#include <queue>
#include <vector>

#define MAX		100001

using namespace std;

int n, k;

queue<pair<int, int>> q;
vector<bool> isVistied(MAX, false);

void BFS();


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	q.push(pair<int, int>(n, 0));

	BFS();

	return 0;
}

void BFS()
{
	while (!q.empty())
	{
		pair<int, int> target = q.front();
		q.pop();

		if (target.first < 0 || target.first > 100000 || isVistied[target.first]) continue;
		isVistied[target.first] = true;

		if (target.first == k)
		{
			cout << target.second;
			break;
		}

		q.push(pair<int, int>(target.first - 1, target.second + 1));
		q.push(pair<int, int>(target.first + 1, target.second + 1));
		q.push(pair<int, int>(target.first * 2, target.second + 1));
	}
}
