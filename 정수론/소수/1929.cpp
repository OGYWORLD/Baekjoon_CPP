#include <iostream>
#include <vector>

using namespace std;

static vector<bool> IsPrime(1000001, true);

void Prime()
{
	IsPrime[0] = false;
	IsPrime[1] = false;

	for (int i = 2; i*i < 1000001; i++)
	{
		if (IsPrime[i])
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				IsPrime[j] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	Prime();

	for (int i = M; i <= N; i++)
	{
		if (IsPrime[i])
		{
			cout << i << "\n";
		}
	}

	return 0;
}
