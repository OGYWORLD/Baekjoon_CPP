#include <iostream>
#include <set>
#include <queue>

using namespace std;

int A, B;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;

	set<long long> s;
	queue<pair<long long, long long>> q;

	q.push(pair<long long, long long>(A, 0));

	while (true)
	{
		if (q.empty())
		{
			cout << "-1";
			break;
		}

		pair<long long, long long> target = q.front();
		q.pop();

		if (target.first > B || s.find(target.first) != s.end()) continue;

		s.insert(target.first);

		if (target.first == B)
		{
			cout << target.second + 1;
			break;
		}

		if (s.find(target.first * 2) == s.end())
		{
			q.push(pair<long long, long long> (target.first * 2, target.second + 1));
		}

		if (s.find(target.first * 10 + 1) == s.end())
		{
			q.push(pair<long long, long long>(target.first * 10 + 1, target.second + 1));
		}

	}

	return 0;
}

#include <iostream>
#include <set>
#include <queue>

using namespace std;

int A, B;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;

	set<long long> s;
	queue<pair<long long, long long>> q;

	q.push(pair<long long, long long>(A, 0));

	while (true)
	{
		if (q.empty())
		{
			cout << "-1";
			break;
		}

		pair<long long, long long> target = q.front();
		q.pop();

		if (target.first > B || s.find(target.first) != s.end()) continue;

		s.insert(target.first);

		if (target.first == B)
		{
			cout << target.second + 1;
			break;
		}

		if (s.find(target.first * 2) == s.end())
		{
			q.push(pair<long long, long long> (target.first * 2, target.second + 1));
		}

		if (s.find(target.first * 10 + 1) == s.end())
		{
			q.push(pair<long long, long long>(target.first * 10 + 1, target.second + 1));
		}

	}

	return 0;
}

