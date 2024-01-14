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

	int cnt = 0;
	int n, m;
	cin >> n;
	cin >> m;

	map<string, int> words;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		words.insert(pair<string, int>(s, 0));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (words.find(s) != words.end())
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}