#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	

	long long N;
	cin >> N;

	long long CopyN = N;

	for (long long i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			CopyN = CopyN - (CopyN / i);
		}

		while (N % i == 0)
		{
			N /= i;
		}
	}

	if (N > 1)
	{
		CopyN = CopyN - (CopyN / N);
	}

	cout << CopyN;

	return 0;
}
