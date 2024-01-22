#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	int N = S.size();

	vector<int> Array(N);
	for (int i = 0; i < N; i++)
	{
		Array[i] = S[i] - '0';
	}

	// Selection Sort
	int Max = -1;
	int MaxIndex = 0;
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (Max < Array[j])
			{
				Max = Array[j];
				MaxIndex = j;
			}
		}

		temp = Array[i];
		Array[i] = Max;
		Array[MaxIndex] = temp;

		cout << Array[i];

		Max = -1;
	}

	return 0;
}

