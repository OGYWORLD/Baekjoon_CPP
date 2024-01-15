#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;

	vector<int> SectionPlus;

	int EntityNumber;
	int TotalPlus = 0;
	SectionPlus.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> EntityNumber;
		TotalPlus += EntityNumber;
		SectionPlus.push_back(TotalPlus);
	}

	int From, To;
	for (int i = 0; i < M; i++)
	{
		cin >> From;
		cin >> To;

		cout << SectionPlus[To] - SectionPlus[From - 1] << "\n";
	}
	
	return 0;
}

