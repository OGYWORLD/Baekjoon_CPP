#include <iostream>
#include <deque>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	deque<int> AdjencyDeque[1002];
	int Node1, Node2;

	AdjencyDeque[0].push_back(1);
	for (int i = 0; i < M; i++)
	{
		cin >> Node1 >> Node2;
		AdjencyDeque[Node1].push_back(Node2);
		AdjencyDeque[Node2].push_back(Node1);
	}

	stack<int> VisitStack;
	int VisitCheckArray[1001];
	for (int i = 0; i < 1001; i++)
	{
		VisitCheckArray[i] = 0;
	}
	int VisitedNode = 0;
	int NodeIndex = 0;
	int Result = 0;
	while (1)
	{
		while (NodeIndex < AdjencyDeque[VisitedNode].size())
		{
			if (VisitCheckArray[AdjencyDeque[VisitedNode][NodeIndex]] == 0)
			{
				VisitStack.push(AdjencyDeque[VisitedNode][NodeIndex]);
				VisitCheckArray[AdjencyDeque[VisitedNode][NodeIndex]] = 1;
				NodeIndex++;
			}
			else
			{
				NodeIndex++;
			}
		}

		if (VisitStack.size() != 0)
		{
			VisitedNode = VisitStack.top();
			VisitStack.pop();
		}
		else
		{
			Result++;

			int i;
			for (i = AdjencyDeque[0][0]; i <= N; i++)
			{
				if (AdjencyDeque[i].size() != 0 && VisitCheckArray[i] == 0)
				{
					VisitedNode = i;
					VisitCheckArray[VisitedNode] = 1;
					break;
				}
			}
			if (i - 1 == N)
			{
				break;
			}
		}

		NodeIndex = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		if (VisitCheckArray[i] == 0)
		{
			Result++;
		}
	}

	cout << Result;

	return 0;
}