#include <iostream>

using namespace std;

int GCD(long long A, long long B)
{
	if (B == 0)
	{
		return A;
	}
	else
	{
		long long R = A % B;
		return GCD(B, R);
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B, G;
	cin >> A >> B;
	
	if (A > B)
	{
		G = GCD(A, B);
	}
	else
	{
		G = GCD(B, A);
	}

	for (long long i = 0; i < G; i++)
	{
		cout << "1";
	}

	return 0;
}
