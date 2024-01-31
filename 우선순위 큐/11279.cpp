#include <iostream>
#include <queue>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int> Q;

	int N;
	cin >> N;

	int Order;
	for (int i = 0; i < N; i++)
	{
		cin >> Order;

		if (Order == 0)
		{
			if (Q.size() != 0)
			{
				cout << Q.top() << "\n";
				Q.pop();
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			Q.push(Order);
		}
	}

	return 0;
}