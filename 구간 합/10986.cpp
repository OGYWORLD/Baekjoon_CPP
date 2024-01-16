#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long N, M;
	cin >> N >> M;

	vector<long> PartSumModVector;
	vector<long> ModCountVector(N, 0);

	long Entity;
	long TotalSum = 0;
	long Cnt = 0;
	for (long i = 0; i < N; i++)
	{
		cin >> Entity;
		TotalSum += Entity;
		PartSumModVector.push_back(TotalSum % M);
		
		if (TotalSum % M == 0)
		{
			Cnt++;
		}

		ModCountVector[TotalSum % M]++;
	}

	for (long i = 0; i < N; i++)
	{
		Cnt += ModCountVector[i] * (ModCountVector[i] - 1) / 2;
	}

	cout << Cnt;
	
	return 0;
}

