#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long N;
	cin >> N;

	vector<int> V;

	int Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		V.push_back(Number);
	}

	sort(V.begin(), V.end());

	int StartIndex = 0;
	int EndIndex = 1;
	int Cnt = 0;
	long NowCheckNumber;
	for (int i = 0; i < N; i++)
	{
		NowCheckNumber = V[i];
		StartIndex = 0;
		EndIndex = 1;

		while (EndIndex < N && StartIndex < N)
		{
			if (V[StartIndex] + V[EndIndex] == NowCheckNumber)
			{
				if (StartIndex != i && EndIndex != i)
				{
					Cnt++;
					break;
				}
				else if (StartIndex == i)
				{
					StartIndex++;
					EndIndex = StartIndex + 1;
				}
				else if (EndIndex == i)
				{
					EndIndex++;
				}
			}
			
			else if (V[StartIndex] + V[EndIndex] < NowCheckNumber)
			{
				EndIndex++;
				if (EndIndex == N)
				{
					StartIndex++;
					EndIndex = StartIndex + 1;
				}
			}
			else
			{
				StartIndex++;
				EndIndex = StartIndex + 1;
			}

		}
	}

	cout << Cnt;
	
	return 0;
}

