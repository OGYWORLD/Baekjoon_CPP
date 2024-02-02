#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A;
	int Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		A.push_back(Number);
	}

	sort(A.begin(), A.end());

	int M;
	int Start = 0;
	int End = N-1;
	int Mid;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Number;

		while (1)
		{
			Mid = (Start + End) / 2;

			if (Start > End)
			{
				cout << "0\n";
				break;
			}

			if (A[Mid] > Number)
			{
				End = Mid-1;
			}
			else if (A[Mid] < Number)
			{
				Start = Mid+1;
			}
			else
			{
				cout << "1\n";
				break;
			}
		}
		Start = 0;
		End = N - 1;

	}

	return 0;
}