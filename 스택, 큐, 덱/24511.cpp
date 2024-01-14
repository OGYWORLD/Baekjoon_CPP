#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<int> DSOrder;
	deque<int> OriginQS;

	int DSOrderNumber;
	int OriginQSNumber;
	for (int i = 0; i < N; i++)
	{
		cin >> DSOrderNumber;
		DSOrder.push_back(DSOrderNumber);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> OriginQSNumber;
		if (DSOrder[i] != 1)
		{
			OriginQS.push_back(OriginQSNumber);
		}
	}

	int M;
	cin >> M;
	int InsertNumber;
	for (int i = 0; i < M; i++)
	{
		cin >> InsertNumber;

		if (OriginQS.size() != 0)
		{
			OriginQS.push_front(InsertNumber);

			cout << OriginQS.back() << " ";

			OriginQS.pop_back();
		}
		else
		{
			cout << InsertNumber << " ";
		}

	}
	
	return 0;
}

