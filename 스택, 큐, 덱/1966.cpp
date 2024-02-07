#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int N, M, Numbers;
	queue<pair<int, int>> Q;
	priority_queue<int> PQ;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> Numbers;
			Q.push(pair<int, int>(j, Numbers));
			PQ.push(Numbers);
		}

		pair<int, int> temp;
		for (int k = 0; ;)
		{
			if (PQ.top() == Q.front().second && Q.front().first == M)
			{
				cout << k+1 << '\n';
				break;
			}

			else if (PQ.top() == Q.front().second)
			{
				PQ.pop();
				Q.pop();
				k++;
			}
			else
			{
				temp = Q.front();
				Q.pop();
				Q.push(temp);
			}
		}
		
		while (Q.size() != 0)
		{
			Q.pop();
		}
		while (PQ.size() != 0)
		{
			PQ.pop();
		}

	}

	

	return 0;
}
