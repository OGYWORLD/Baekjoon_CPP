#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<pair<int, int>> PQ;

	int Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;

		if (Number == 0)
		{
			if (PQ.size() == 0)
			{
				cout << "0\n";
			}
			else
			{
				cout << -PQ.top().second << "\n";
				PQ.pop();
			}
		}
		else
		{
			if (Number < 0)
			{
				PQ.push(pair<int, int>(Number, -Number));
			}
			else
			{
				PQ.push(pair<int, int>(-Number, -Number));
			}
		}
	}
	

	return 0;
}

