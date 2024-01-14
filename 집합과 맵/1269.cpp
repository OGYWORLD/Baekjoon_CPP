#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ANumber, BNumber;
	cin >> ANumber;
	cin >> BNumber;

	map<int, int> ASet;
	map<int, int> BSet;

	// Get Set
	int TempNumber = 0;
	for (int i = 0; i < ANumber; i++)
	{
		cin >> TempNumber;
		ASet.insert(pair<int, int>(TempNumber, 0));
	}

	for (int i = 0; i < BNumber; i++)
	{
		cin >> TempNumber;
		BSet.insert(pair<int, int>(TempNumber, 0));
	}

	// Search
	map<int, int>::iterator iter;
	int AInBNumber = 0;
	for (iter = ASet.begin(); iter != ASet.end(); iter++)
	{
		if (BSet.find(iter->first) != BSet.end())
		{
			AInBNumber++;
		}
	}

	cout << BSet.size() - AInBNumber + ASet.size() - AInBNumber;

	return 0;
}