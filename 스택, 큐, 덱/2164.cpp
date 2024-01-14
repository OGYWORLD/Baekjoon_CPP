#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> Card;

	for (int i = 1; i <= N; i++)
	{
		Card.push(i);
	}
	
	while (1)
	{
		if (Card.size() == 1)
		{
			cout << Card.front();
			break;
		}

		Card.pop();
		Card.push(Card.front());
		Card.pop();
	}
	
	return 0;
}
