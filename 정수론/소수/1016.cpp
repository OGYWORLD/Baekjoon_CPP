#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long Min, Max;
	cin >> Min >> Max;

	vector<bool> IsPrime(10000000, true);
	set<long long> YesYes;

	long long SMax = sqrt(Max);

	IsPrime[0] = false;
	IsPrime[1] = false;
	for (long long i = 2; i <= SMax; i++)
	{
		if (IsPrime[i])
		{
			for (long long j = i * i; j <= SMax; j += i)
			{
				IsPrime[j] = false;
			}
			
			long long k = i * i;

			long long p;
			if (Min % k != 0)
			{
				p = (Min / k + 1) * k;
			}
			else
			{
				p = Min;
			}

			for (long long j = p; j <= Max; j += k)
			{
				YesYes.insert(j);

				if (Max - j < k)
				{
					break;
				}
			}
		}
	}

	long long S = YesYes.size();

	cout << Max - Min - S + 1;


	return 0;
}
