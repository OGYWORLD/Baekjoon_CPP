#include <iostream>
#include <vector>

#define LLONG_MAX 9223372036854775807

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;

	vector<long long> trees(n);

	long long srt = 0;
	long long end = 0;
	long long total = 0;

	int index = 0;
	while (index < n)
	{
		cin >> trees[index];
		total += trees[index];

		if (trees[index] > end) end = trees[index];

		index++;
	}

	long long mid = total / n;

	long long max = LLONG_MAX;
	long long ans = 0;
	while (srt <= end)
	{
		long long result = 0;
		for (int i = 0; i < trees.size(); i++)
		{
			long long take = trees[i] - mid;
			if (take < 0) continue;
			result += take;
		}

		if (result - m > -1 && max > result)
		{
			max = result;
			ans = mid;
		}
		
		if (result > m)
		{
			srt = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

		mid = (srt + end) / 2;
	}

	cout << ans;


	return 0;
}