#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool IsPrime(int n)
{
	if (n == 0 || n == 1)
	{
		return false;
	}
	else if (n == 2 || n == 3)
	{
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}

void DFS(int SearchNumber, int N, int Cnt)
{
	int NewSearchNumber;
	if (IsPrime(SearchNumber))
	{
		Cnt++;
		if (Cnt == N)
		{
			cout << SearchNumber << "\n";
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				NewSearchNumber = SearchNumber * 10 + i;
				DFS(NewSearchNumber, N, Cnt);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	int Cnt = 0;
	for (int i = 0; i <= 9; i++)
	{
		DFS(i, N, Cnt);
	}

	return 0;
}