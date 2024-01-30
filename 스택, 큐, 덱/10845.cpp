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

	string Order;
	queue<int> Q;
	int PushNumber;
	int PopNumber;
	for (int i = 0; i < N; i++)
	{
		cin >> Order;
		if (Order.compare("push") == 0)
		{
			cin >> PushNumber;
			Q.push(PushNumber);
		}

		else if (Order.compare("pop") == 0)
		{
			if (Q.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				PopNumber = Q.front();
				Q.pop();
				cout << PopNumber << "\n";
			}
		}

		else if (Order.compare("size") == 0)
		{
			cout << Q.size() << "\n";
		}

		else if (Order.compare("empty") == 0)
		{
			cout << Q.empty() << "\n";
		}

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