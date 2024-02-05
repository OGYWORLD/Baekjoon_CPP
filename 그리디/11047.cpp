#include <iostream>
#include <vector>


using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> Coin(N);
	for (int i = 0; i < N; i++)
	{
		cin >> Coin[i];
	}

	int Cnt = 0;
	for (int i = N - 1; i > -1; i--)
	{
		if (Coin[i] <= K)
		{
			Cnt += K / Coin[i];
			K %= Coin[i];
		}
	}

	cout << Cnt;

	return 0;
}