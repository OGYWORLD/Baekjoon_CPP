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

	vector<int> V;
	int Entity;
	for (int i = 0; i < N; i++)
	{
		cin >> Entity;
		V.push_back(Entity);
	}

	int Temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (V[j] > V[j + 1])
			{
				Temp = V[j];
				V[j] = V[j + 1];
				V[j + 1] = Temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << V[i] << "\n";
	}

	return 0;
}