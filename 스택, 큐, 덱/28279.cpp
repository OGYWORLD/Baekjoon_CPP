#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	deque<int> D;

	int N;
	cin >> N;

	int OrderNumber;
	int PushNumber;
	for (int i = 0; i < N; i++)
	{
		cin >> OrderNumber;

		// 1. push_front
		if (OrderNumber == 1)
		{
			cin >> PushNumber;
			D.push_front(PushNumber);
		}

		// 2.push_back
		else if (OrderNumber == 2)
		{
			cin >> PushNumber;
			D.push_back(PushNumber);
		}

		// 3. print front and pop_front
		else if (OrderNumber == 3)
		{
			if (D.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << D.front() << "\n";
				D.pop_front();
			}
		}

		// 4. print back and pop_back
		else if (OrderNumber == 4)
		{
			if (D.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << D.back() << "\n";
				D.pop_back();
			}
		}

		// 5. check size
		else if (OrderNumber == 5)
		{
			cout << D.size() << "\n";
		}

		// 6. check empty
		else if (OrderNumber == 6)
		{
			cout << D.empty() << "\n";
		}

		// 7. print front
		else if (OrderNumber == 7)
		{
			if (D.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << D.front() << "\n";
			}
		}

		// 8. print back
		else if (OrderNumber == 8)
		{
			if (D.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << D.back() << "\n";
			}
		}
	}

	return 0;
}

