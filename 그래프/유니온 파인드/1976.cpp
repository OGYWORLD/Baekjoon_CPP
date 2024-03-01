#include <iostream>
#include <vector>


using namespace std;

static vector<int> Cities;

int FindRepNode(int Node)
{
	if (Cities[Node] == Node)
	{
		return Node;
	}
	else
	{
		return Cities[Node] = FindRepNode(Cities[Node]);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;

	Cities.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		Cities[i] = i;
	}

	int GetEdge;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> GetEdge;

			if (GetEdge == 1)
			{
				int NowRepNode = FindRepNode(i);
				int GetRepNode = FindRepNode(j);

				if (NowRepNode != GetRepNode)
				{
					Cities[GetRepNode] = NowRepNode;
				}
			}
		}
	}
	
	if (M == 1)
	{
		cout << "YES\n";
	}
	else
	{
		vector<int> TourList(M);
		for (int i = 0; i < M; i++)
		{
			cin >> TourList[i];
		}

		int Cnt = 0;
		int A, B;
		for (int i = 1; i < M; i++)
		{
			A = FindRepNode(TourList[i-1]);
			B = FindRepNode(TourList[i]);

			if (A == B)
			{
				Cnt++;
			}
		}

		if (Cnt == M - 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}
