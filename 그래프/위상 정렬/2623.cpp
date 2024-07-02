#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> adj[1001];
	vector<int> parentNum;

	parentNum.resize(n+1);

	int preOrder, order;
	int singerNum;
	for (int i = 0; i < m; i++)
	{
		cin >> singerNum;

		for (int j = 0; j < singerNum; j++)
		{
			cin >> order;

			if (j != 0)
			{
				adj[preOrder].push_back(order);
				parentNum[order]++;
			}

			preOrder = order;
		}
	}

	queue<int> parentZero;
	for (int i = 1; i <= n; i++)
	{
		if (parentNum[i] == 0)
		{
			parentZero.push(i);
		}
	}

	// cycle
	if (parentZero.size() == 0)
	{
		cout << "0";

		return 0;
	}

	int popNum = 0;

	vector<int> result;
	while (parentZero.size() != 0)
	{
		int zeroParentNode = parentZero.front();
		parentZero.pop();
		popNum++;

		result.push_back(zeroParentNode);

		if (popNum == n && adj[zeroParentNode].size() != 0)
		{
			popNum = 0;
			break;
		}

		for (int i = 0; i < adj[zeroParentNode].size(); i++)
		{
			parentNum[adj[zeroParentNode][i]]--;

			if (parentNum[adj[zeroParentNode][i]] == 0)
			{
				parentZero.push(adj[zeroParentNode][i]);
			}
		}

	}

	if (popNum < n)
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << "\n";
	}


	return 0;
}
