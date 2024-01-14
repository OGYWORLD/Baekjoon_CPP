#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int Euclidean(int Max, int Min)
{
	if (Min == 0)
	{
		return Max;
	}
	else
	{
		int R = Max % Min;
		return Euclidean(Min, R);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int S1, M1, S2, M2;

	cin >> S1;
	cin >> M1;

	cin >> S2;
	cin >> M2;

	int A = S1 * M2 + S2 * M1;
	int B = M1 * M2;

	int MinFactor = Euclidean(max(A, B), min(A, B));

	cout << A / MinFactor << " " << B / MinFactor;
	
	return 0;
}