#include <iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, k;
	cin >> N >> k;

	long long Start = 1;
	long long End = k;
	long long Mid = (Start + End) / 2;
	long long SmallerThanMidCnt = 0;

	long long R;
	long long Result;
	while (Start <= End)
	{
		for (int i = 1; i <= N; i++)
		{
			R = Mid / i;
			if (R > N)
			{
				SmallerThanMidCnt += N;
			}
			else
			{
				SmallerThanMidCnt += R;
			}
		}

		if (SmallerThanMidCnt < k)
		{
			Start = ++Mid;
			SmallerThanMidCnt = 0;
			Mid = (Start + End) / 2;
		}
		else
		{
			Result = Mid;
			End = --Mid;
			SmallerThanMidCnt = 0;
			Mid = (Start + End) / 2;
		}
	}

	cout << Result;


	return 0;
}