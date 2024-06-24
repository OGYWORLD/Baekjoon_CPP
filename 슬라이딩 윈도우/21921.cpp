#include <iostream>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;

	int srt = 0;
	int end = x - 1;

	vector<int> v(n);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];

		if (i < x)
		{
			sum += v[i];
		}
	}

	int max = -1;
	int cnt = 0;
	while (true)
	{
		if (max < sum)
		{
			cnt = 0;
			max = sum;
		}
		else if (max == sum)
		{
			cnt++;
		}

		sum -= v[srt];
		srt++;
		end++;
		if (end >= n)
		{
			break;
		}
		sum += v[end];
	}

	if (max == 0)
	{
		cout << "SAD";
	}
	else
	{
		cout << max << "\n" << cnt + 1;
	}

	return 0;
}