#include <iostream>
#include <deque>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	deque<int> D;

	string s;
	int Entity;
	for (int i = 0; i < N; i++)
	{
		cin >> s;

		if (s.compare("push_front") == 0)
		{
			cin >> Entity;
			D.push_front(Entity);
		}
		else if (s.compare("push_back") == 0)
		{
			cin >> Entity;
			D.push_back(Entity);
		}
		else if (s.compare("pop_front") == 0)
		{
			if (D.size() != 0)
			{
				int p = D.front();
				D.pop_front();

				cout << p << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (s.compare("pop_back") == 0)
		{
			if (D.size() != 0)
			{
				int p = D.back();
				D.pop_back();

				cout << p << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (s.compare("size") == 0)
		{
			cout << D.size() << "\n";
		}
		else if (s.compare("empty") == 0)
		{
			cout << D.empty() << "\n";
		}
		else if (s.compare("front") == 0)
		{
			if (D.size() != 0)
			{
				int p = D.front();

				cout << p << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else
		{
			if (D.size() != 0)
			{
				int p = D.back();

				cout << p << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
	
	return 0;
}
