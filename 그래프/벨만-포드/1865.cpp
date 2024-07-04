#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> info;

vector<info> adj;
vector<int> minCost;

bool isCycleExist;

int n, m, w;

void BellmanFord();

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int index = 0;
	while (index < tc)
	{
		cin >> n >> m >> w;

		minCost.resize(n + 1, 9999999);

		int n1, n2, cost;
		// Get Normal Node Info

		for (int i = 0; i < m; i++)
		{
			cin >> n1 >> n2 >> cost;

			adj.push_back(make_tuple(n1, n2, cost));
			adj.push_back(make_tuple(n2, n1, cost));
		}

		// Get WormHole Node Info
		for (int i = 0; i < w; i++)
		{
			cin >> n1 >> n2 >> cost;

			adj.push_back(make_tuple(n1, n2, -cost));
		}
		
		BellmanFord();
		
		if (isCycleExist)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}

		adj.clear();
		minCost.clear();
		isCycleExist = false;

		index++;
	}


	return 0;
}

void BellmanFord()
{
	// minCost Update
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < adj.size(); j++)
		{
			int preNode = get<0>(adj[j]);
			int postNode = get<1>(adj[j]);
			int edgeCost = get<2>(adj[j]);

			if (minCost[postNode] > minCost[preNode] + edgeCost)
			{
				minCost[postNode] = minCost[preNode] + edgeCost;
			}
		}
	}

	// Check Negative Cycle
	for (int j = 0; j < adj.size(); j++)
	{
		int preNode = get<0>(adj[j]);
		int postNode = get<1>(adj[j]);
		int edgeCost = get<2>(adj[j]);

		if (minCost[postNode] > minCost[preNode] + edgeCost)
		{
			isCycleExist = true;
			break;
		}
	}
}
