#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> SGCard;

	long long GetCard;
	for (int i = 0; i < n; i++)
	{
		cin >> GetCard;
		SGCard.push_back(GetCard);
	}

	sort(SGCard.begin(), SGCard.end());

	int m;
	cin >> m;
	long long GivenCard;
	for (int i = 0; i < m; i++)
	{
		cin >> GivenCard;
		cout << upper_bound(SGCard.begin(), SGCard.end(), GivenCard) - lower_bound(SGCard.begin(), SGCard.end(), GivenCard) << " ";
	}

	return 0;
}
