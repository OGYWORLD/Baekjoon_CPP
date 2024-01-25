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

	vector<int> Array(10001, 0);
	int Number;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		Array[Number]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (Array[i] != 0)
		{
			for (int j = 0; j < Array[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}
	

	return 0;
}