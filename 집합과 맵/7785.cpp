#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<string, int> list;

	string name;
	string EnterOrLeave;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		cin >> EnterOrLeave;

		if (!EnterOrLeave.compare("enter"))
		{
			list.insert(pair<string, int>(name, 0));
		}
		else
		{
			list.erase(name);
		}
	}

	map<string, int>::reverse_iterator it;
	for (it = list.rbegin(); it != list.rend(); it++)
	{
		cout << it->first << "\n";
	}

	return 0;
}