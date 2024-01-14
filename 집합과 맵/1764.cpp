#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;

	map<string, int> DontHear;

	string Name;
	for (int i = 0; i < N; i++)
	{
		cin >> Name;
		DontHear.insert(pair<string, int>(Name, 0));
	}

	int Count = 0;
	vector<string> DontHearSee;
	for (int i = 0; i < M; i++)
	{
		cin >> Name;
		if (DontHear.find(Name) != DontHear.end())
		{
			DontHearSee.push_back(Name);
			Count++;
		}
	}

	cout << Count << "\n";
	sort(DontHearSee.begin(), DontHearSee.end());

	for (int i = 0; i < Count; i++)
	{
		cout << DontHearSee[i] << "\n";
	}

	return 0;
}
