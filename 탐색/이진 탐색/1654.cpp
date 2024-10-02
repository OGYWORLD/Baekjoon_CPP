#include <iostream>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;

	vector<int> line(k);
	
	long long max = -1;
	long long total = 0;
	int index = 0;
	while (index < k)
	{
		cin >> line[index];
		total += line[index];

		if (max < line[index])
		{
			max = line[index];
		}

		index++;
	}

	long long srt = 1;
	long long end = max;
	long long mid = total / k;
	while (true)
	{
		if (srt > end)
		{
			cout << mid;
			break;
		}

		int possible = 0;
		for (int i = 0; i < k; i++)
		{
			possible += line[i] / mid;
		}

		if (possible < n)
		{
			end = mid - 1;
		}
		else
		{
			srt = mid + 1;
		}

		mid = (srt + end) / 2;
	}

	return 0;
}
