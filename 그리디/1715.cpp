#include <iostream>
#include <queue>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<int> Card;
	int GetCardCnt;
	for (int i = 0; i < N; i++)
	{
		cin >> GetCardCnt;
		Card.push(-GetCardCnt);
	}

	int Sum = 0;
	int Result = 0;
	while (Card.size() != 1)
	{
		for (int i = 0; i < 2; i++)
		{
			Sum += Card.top();
			Card.pop();
		}

		Card.push(Sum);

		Result += Sum;
		Sum = 0;
	}

	cout << -Result;

	return 0;
}