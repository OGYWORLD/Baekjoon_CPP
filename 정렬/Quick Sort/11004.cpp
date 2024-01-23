#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> Array;
	int Entity;
	for (int i = 0; i < N; i++)
	{
		cin >> Entity;
		Array.push_back(Entity);
	}

	sort(Array.begin(), Array.end());

	cout << Array[K - 1];

	return 0;
}


/* Quick Sort
#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& A, int first, int end)
{
	if (first >= end)
	{
		return;
	}

	int pivot = first;
	int low = first + 1;
	int high = end;
	int temp;
	while (low <= high)
	{
		while (A[low] < A[pivot] && low <= end)
		{
			low++;
		}
		while(A[high] > A[pivot] && high > first)
		{
			high--;
		}

		if (low >= high)
		{
			break;
		}

		temp = A[high];
		A[high] = A[low];
		A[low] = temp;
	}

	temp = A[high];
	A[high] = A[pivot];
	A[pivot] = temp;

	QuickSort(A, first, high - 1);
	QuickSort(A, high+1, end);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> Array;
	int Entity;
	for (int i = 0; i < N; i++)
	{
		cin >> Entity;
		Array.push_back(Entity);
	}

	QuickSort(Array, 0, N - 1);

	cout << Array[K - 1];

	return 0;
}
*/