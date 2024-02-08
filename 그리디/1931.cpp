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
	
	int Start, End;
	
	priority_queue<pair<int, int>> PQ;
	for (int i = 0; i < N; i++)
	{
		cin >> Start >> End;
		PQ.push(pair<int, int>(-End, -Start));
	}

	End = -PQ.top().first;
	Start = -PQ.top().second;
	PQ.pop();

	int Cnt = 0;
	for (int i = 0; PQ.size() != 0; i++)
	{
		if (End <= -PQ.top().second)
		{
			End = -PQ.top().first;
			Start = -PQ.top().second;
			PQ.pop();

			Cnt++;
		}
		else
		{
			PQ.pop();
		}
	}

	Cnt++;
	cout << Cnt;

	return 0;
}
