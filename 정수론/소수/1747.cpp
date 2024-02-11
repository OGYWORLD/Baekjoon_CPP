#include <iostream>
#include <vector>
#include <string>

using namespace std;

static vector<bool> IsPrime(1003002, true);

void Prime()
{
	IsPrime[0] = false;
	IsPrime[1] = false;

	for (int i = 2; i * i < 1003002; i++)
	{
		if (IsPrime[i])
		{
			for (int j = i * i; j < 1003002; j += i)
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

	Prime();

	int N;
	cin >> N;

	string s;
	for (int i = N; i <= 1003001; i++)
	{
		if (IsPrime[i])
		{
			s = to_string(i);

			int Size = s.size();
			int Cnt = 0;
			for (int j = 0; j < Size; j++)
			{
				if (s[j] == s[Size - 1 - j])
				{
					Cnt++;
				}
			}

			if (Size == Cnt)
			{
				cout << i;
				break;
			}

		}
	}

	return 0;
}
