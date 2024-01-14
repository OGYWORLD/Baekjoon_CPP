#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int Euclidean(long long& Max, long long& Min)
{
	if (Min == 0)
	{
		return Max;
	}
	else
	{
		long long R = Max % Min;
		return Euclidean(Min, R);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B;
	
	cin >> A;
	cin >> B;

	cout << A * B / Euclidean(A, B);
	
	return 0;
}