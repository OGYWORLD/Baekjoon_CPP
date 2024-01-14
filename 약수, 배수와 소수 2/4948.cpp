#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

bool Prime(int& Number)
{
	if (Number <= 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= sqrt(Number); i++)
		{
			if (Number % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = -1;
	int Cnt = 0;

	
	map<int, int> PrimeMap;

	for (int j = 2; j <= 123456*2; j++)
	{
		if (Prime(j))
		{
			PrimeMap.insert(pair<int, int>(j, 0));
		}
	}

	while (1)
	{
		cin >> N;

		if (N == 0)
		{
			break;
		}
		
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (PrimeMap.find(i) != PrimeMap.end())
			{
				Cnt++;
			}
		}

		cout << Cnt << "\n";

		Cnt = 0;
	}
	
	return 0;
}