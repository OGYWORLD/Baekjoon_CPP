#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int Eculidean(int Max, int Min)
{
	if (Min == 0)
	{
		return Max;
	}
	else
	{
		int R = Max % Min;
		return Eculidean(Min, R);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int T;
	vector<int> OriginTree;
	vector<int> DifTree;
	for (int i = 0; i < N; i++)
	{
		cin >> T;
		OriginTree.push_back(T);
	}

	for (int i = 1; i < N; i++)
	{
		DifTree.push_back(OriginTree.at(i) - OriginTree.at(i - 1));
	}

	int MinFactor = Eculidean(DifTree.at(1), DifTree.at(0));
	for (int i = 2; i < N-1; i++)
	{
		MinFactor = Eculidean(DifTree.at(i), MinFactor);
	}


	int Cnt = 0;
	for (int i = 1; i < N; i++)
	{
		Cnt += (OriginTree.at(i) - OriginTree.at(i - 1)) / MinFactor - 1;
	}

	cout << Cnt;

	return 0;
}

