#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

static vector<bool> IsPrime(10000001, true);
static set<long long> S;

void Prime(long long& A, long long& B)
{
	long long SQB = (long long)sqrt(B);
	IsPrime[0] = false;
	IsPrime[1] = false;

	for (long long i = 2; i <= SQB; i++)
	{
		if (IsPrime[i])
		{
			for (long long j = i * i; j <= SQB; j += i)
			{
				IsPrime[j] = false;
			}
			
			for (long long j = i * i; j <= B; j *= i)
			{

				if (j >= A)
				{
					S.insert(j);
				}

				if (B / j < i)
				{
					break;
				}
			}
		}
	}
}

int main()

{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	Prime(A, B);

	cout << S.size();


	return 0;
}
