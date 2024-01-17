#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

	int StartPoint = 1;
	int EndPoint = 1;

	int Cnt = 0;
	int Sum = 1;
	while (EndPoint <= N)
	{
		if (Sum == N)
		{
			Cnt++;
			EndPoint++;
			Sum += EndPoint;

			Sum -= StartPoint;
			StartPoint++;

		}

		if (Sum < N)
		{
			EndPoint++;
			Sum += EndPoint;
		}
		else
		{
			Sum -= StartPoint;
			StartPoint++;
		}
	}

	cout << Cnt;

	return 0;
}

