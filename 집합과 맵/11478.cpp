#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;
	int SLen = S.size();

	map<string, int> SMap;

	for (int i = 1; i <= SLen; i++)
	{
		for (int j = 0; j < SLen - i+1; j++)
		{
			SMap.insert(pair<string, int>(S.substr(j, i), 0));
		}
	}

	cout << SMap.size();

	return 0;
}