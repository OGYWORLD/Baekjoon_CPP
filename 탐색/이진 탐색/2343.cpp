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

	int Entry;
	vector<int> A;
	
	int Max = -1;
	int Sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Entry;
		A.push_back(Entry);
		Sum += Entry;

		if (Max < Entry)
		{
			Max = Entry;
		}
	}
	
	int Start = Max;
	int End = Sum;
	int MaxTime = (Start + End)/ 2;
	int TotalSum = 0;
	int DivCnt = 0;
	while (Start <= End)
	{
		int MaxTime = (Start + End) / 2;
		int TotalSum = 0;
		int DivCnt = 0;

		for (int i = 0; i < N; i++)
		{
			if (TotalSum + A[i] > MaxTime)
			{
				TotalSum = 0;
				DivCnt++;
			}

			TotalSum += A[i];
		}

		if (TotalSum != 0)
		{
			DivCnt++;
		}

		if (DivCnt > M)
		{
			Start = MaxTime + 1;
		}
		else
		{
			End = MaxTime - 1;
		}
	}

	cout << Start;

	return 0;
}