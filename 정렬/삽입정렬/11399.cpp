#include <iostream>
#include <vector>

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
	
	// Insertion Sort
	int temp;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] < A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	int Result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			Result += A[j];
		}
	}

	cout << Result;

	return 0;
}

