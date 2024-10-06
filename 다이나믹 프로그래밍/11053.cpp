#include <iostream>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> dp(N, 0);

	int index = 0;
	while (index < N)
	{
		cin >> v[index];
		
		index++;
	}

	int max = -1;
	for (int i = 0; i < N; i++)
	{
		int continuous = 0;
		for (int j = 0; j < i; j++)
		{
			if (dp[j] >= continuous && v[j] < v[i])
			{
				continuous++;
			}
		}

		dp[i] = continuous;

		if (max < continuous)
		{
			max = continuous;
		}
	}

	cout << max + 1;

	return 0;
}