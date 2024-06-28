#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
bool isVisited[51];

// category 0: get rid of delete node, 1: check leaf node
void DFS(int node, int category);

int leafNodeNum;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int node;

	int index = 0;
	int leafNode;
	while (index < n)
	{
		cin >> node;

		if (node == -1)
		{
			leafNode = index;
		}
		else
		{
			adj[node].push_back(index);
		}

		index++;
	}

	int delNode;
	cin >> delNode;

	// get rid of delete node
	DFS(delNode, 0);

	// check leaf node
	if (!isVisited[leafNode])
	{
		DFS(leafNode, 1);
	}

	cout << leafNodeNum;

	return 0;
}


void DFS(int node, int category)
{
	isVisited[node] = true;
	
	int cnt = 0;
	for (int i = 0; i < adj[node].size(); i++)
	{
		if (!isVisited[adj[node][i]])
		{
			cnt++;
			DFS(adj[node][i], category);
		}
	}

	if (category == 1 && cnt == 0)
	{
		leafNodeNum++;
	}
}
