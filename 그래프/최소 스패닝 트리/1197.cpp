#include <iostream>
#include <queue>

#define MAX_NODE_NUM	10001

using namespace std;

typedef struct Edge
{
	int n1, n2, cost;

	bool operator > (const Edge& cp) const
	{
		return cost > cp.cost;
	}
}Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> edgeInfo;
int repNode[MAX_NODE_NUM];

int v, e;

void Init();
int UnionFind(int node);
void MST();

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> v >> e;

	Init();

	int n1, n2, cost;
	int index = 0;
	while (index < e)
	{
		cin >> n1 >> n2 >> cost;

		edgeInfo.push(Edge{ n1, n2, cost });

		index++;
	}
	
	MST();

	return 0;
}

void Init()
{
	for (int i = 0; i <= v; i++)
	{
		repNode[i] = i;
	}
}

int UnionFind(int node)
{
	if (node == repNode[node])
	{
		return node;
	}
	else
	{
		return repNode[node] = UnionFind(repNode[node]);
	}
}

void MST()
{
	int totalCost = 0;
	int edgeCnt = 0;

	while (edgeCnt < v - 1)
	{
		int sNode = edgeInfo.top().n1;
		int eNode = edgeInfo.top().n2;
		int cost = edgeInfo.top().cost;

		edgeInfo.pop();

		if (UnionFind(sNode) != UnionFind(eNode))
		{
			totalCost += cost;

			int sParent = repNode[sNode];
			int eParent = repNode[eNode];

			if (sParent != eParent)
			{
				repNode[eParent] = sParent;
			}

			edgeCnt++;
		}
	}

	cout << totalCost;
}