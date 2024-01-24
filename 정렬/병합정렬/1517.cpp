#include <iostream>
#include <deque>

using namespace std;

void Merge(deque<long long>& A, deque<long long>& S, long long left, long long right, long long& Result)
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
			Result += index2 - SIndex;
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

void MergeSort(deque<long long>& A, deque<long long>& S, long long left, long long right, long long& Result)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		MergeSort(A, S, left, mid, Result);
		MergeSort(A, S, mid + 1, right, Result);
		Merge(A, S, left, right, Result);
	}
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	deque<long long> array;
	deque<long long> saved(N, 0); 

	long long Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		array.push_back(Number);
	}

	long long Result = 0;
	MergeSort(array, saved, 0, N - 1, Result);

	cout << Result;

	return 0;
}