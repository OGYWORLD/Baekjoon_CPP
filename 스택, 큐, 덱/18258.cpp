#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string Order;
	int OrderNumber;
	queue<int> Q;
	for (int i = 0; i < N; i++)
	{
		cin >> Order;

		// push
		if(Order.compare("push") == 0)
		{
			cin >> OrderNumber;
			Q.push(OrderNumber);
		}

		// pop
		else if(Order.compare("pop") == 0)
		{
			if (Q.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << "\n";
				Q.pop();
			}
		}

		// size
		else if(Order.compare("size") == 0)
		{
			cout << Q.size() << "\n";
		}

		// empty
		else if (Order.compare("empty") == 0)
		{
			cout << Q.empty() << "\n";
		}

		// front
		else if (Order.compare("front") == 0)
		{
			if (Q.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << "\n";
			}
		}

		// back
		else if (Order.compare("back") == 0)
		{
			if (Q.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.back() << "\n";
			}
		}
	}
	
	return 0;
}