#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int& TargetNumber)
{
	if (TargetNumber == 1)
	{
		return false;
	}
	else if (TargetNumber < 4)
	{
		return true;
	}

	for (int i = 2; i <= sqrt(TargetNumber); i++)
	{
		if (TargetNumber % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;

	cin >> M;
	cin >> N;

	for (int T = M; T <= N; T++)
	{
		if (IsPrime(T))
		{
			cout << T << "\n";
		}
	}

	return 0;
}
