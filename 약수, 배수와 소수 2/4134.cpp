#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	long long Number;
	long long Carry = 0;
	int Flag = 0;
	for (int Index = 0; Index < N; Index++)
	{
		cin >> Number;

		if (Number < 2)
		{
			cout << 2 << "\n";
		}
		else
		{
			while (1)
			{
				for (int i = 2; i <= (int)sqrt(Number + Carry); i++)
				{
					if ((Number + Carry) % i == 0)
					{
						Flag = 1;
						break;
					}
				}

				if (Flag == 0)
				{
					break;
				}

				Flag = 0;
				Carry++;
			}

			cout << Number + Carry << "\n";
			Carry = 0;
		}
	}

	return 0;
}