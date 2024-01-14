#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool IsPrimeArray[1000001];

	for (int i = 2; i < 1000001; i++)
	{
		IsPrimeArray[i] = true;
	}
	IsPrimeArray[0] = false;
	IsPrimeArray[1] = false;

	for (int i = 2; i * i < 1000001; i++)
	{
		if (IsPrimeArray[i])
		{
			for (int j = i*i; j < 1000001; j += i)
			{
				IsPrimeArray[j] = false;
			}
		}
	}

	int T;
	cin >> T;

	int Number;
	int Cnt = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> Number;

		for (int j = 2; j <= Number; j++)
		{
			if (IsPrimeArray[j] && IsPrimeArray[Number - j])
			{
				Cnt++;
			}
		}

		if (Cnt % 2 == 0)
		{
			cout << Cnt / 2 << "\n";
		}
		else
		{
			cout << Cnt / 2 + 1 << "\n";
		}
		Cnt = 0;
	}
	
	return 0;
}