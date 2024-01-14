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

	int T;
	cin >> T;

	int A, B;
	int LCM = 1;
	for (int i = 0; i < T; i++)
	{
		cin >> A;
		cin >> B;

		LCM = Euclidean(max(A, B), min(A, B));
		cout << A * B / LCM << "\n";
	}
	
	return 0;
}
