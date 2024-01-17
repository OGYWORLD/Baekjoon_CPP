#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	vector<int> NumberVector;
	int GetNumber;
	for (int i = 0; i < N; i++)
	{
		cin >> GetNumber;
		NumberVector.push_back(GetNumber);
	}

	int StartPoint = 0;
	int EndPoint = 1;
	int Cnt = 0;
	while (StartPoint < N-1)
	{
		if ((NumberVector[StartPoint] + NumberVector[EndPoint]) == M)
		{
			Cnt++;
			StartPoint++;
			EndPoint = StartPoint + 1;
		}
		else
		{
			EndPoint++;
		}

		if (EndPoint >= N)
		{
			StartPoint++;
			EndPoint = StartPoint + 1;
		}

	}

	cout << Cnt;

	return 0;
}