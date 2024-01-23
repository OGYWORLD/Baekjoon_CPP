#include <iostream>
#include <deque>

using namespace std;

void Merge(deque<int>& A, deque<int>& S, int left, int right)
{
	int mid = (left + right) / 2;
	int index1 = left;
	int index2 = mid + 1;
	int SIndex = left;

	while (index1 <= mid && index2 <= right)
	{
		if (A[index1] > A[index2])
		{
			S[SIndex] = A[index2];
			index2++;
		}
		else
		{
			S[SIndex] = A[index1];
			index1++;
		}
		SIndex++;
	}

	if (index1 > mid)
	{
		for (int i = index2; i <= right; i++)
		{
			S[SIndex] = A[i];
			SIndex++;
		}
	}
	else
	{
		for (int i = index1; i <= mid; i++)
		{
			S[SIndex] = A[i];
			SIndex++;
		}
	}

	for (int i = left; i <= right; i++)
	{
		A[i] = S[i];
	}
}

void MergeSort(deque<int>& A, deque<int>& S, int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		MergeSort(A, S, left, mid);
		MergeSort(A, S, mid + 1, right);
		Merge(A, S, left, right);
	}
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	deque<int> array;
	deque<int> saved(N, 0);

	int Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		array.push_back(Number);
	}

	MergeSort(array, saved, 0, N-1);

	for (int i = 0; i < N; i++)
	{
		cout << array[i] << "\n";
	}

	return 0;
}