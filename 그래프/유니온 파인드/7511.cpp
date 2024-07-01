#include <iostream>
#include <vector>

using namespace std;

vector<int> friends;

int FindRepNode(int node);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	int n, k;
	int index = 0;
	while (index < t)
	{
		cout << "Scenario " << index + 1 << ":\n";

		cin >> n >> k;

		friends.resize(n);

		// init
		for (int i = 0; i < n; i++)
		{
			friends[i] = i;
		}

		int a, b;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			
			int aRep = FindRepNode(a);
			int bRep = FindRepNode(b);

			if (aRep != bRep)
			{
				friends[bRep] = aRep;
			}
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			if (FindRepNode(a) != FindRepNode(b))
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}

		cout << "\n";

		index++;
	}

	return 0;
}

int FindRepNode(int node)
{
	if (friends[node] == node)
	{
		return node;
	}
	else
	{
		return FindRepNode(friends[node]);
	}
}
