#include <iostream>


using namespace std;

static int Adj[50][50];
static bool IsVisited[50][50];
static int Depth = 0;

static int DeltaX[4] = { -1, 1, 0, 0 };
static int DeltaY[4] = { 0, 0, -1, 1 };

void DFS(int XNode, int YNode, int M, int N)
{
	IsVisited[XNode][YNode] = true;
	Depth++;

	for (int i = 0; i < 4; i++)
	{
		if (XNode + DeltaX[i] > -1 && YNode + DeltaY[i] > -1 && XNode + DeltaX[i] < M && YNode + DeltaY[i] < N)
		{
			if (!IsVisited[XNode + DeltaX[i]][YNode + DeltaY[i]] && Adj[XNode + DeltaX[i]][YNode + DeltaY[i]] == 1)
			{
				DFS(XNode + DeltaX[i], YNode + DeltaY[i], M, N);
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			Adj[i][j] = 0;
			IsVisited[i][j] = false;
		}
	}

	int T;
	cin >> T;

	int index = 0;
	int M, N, K;
	while (index < T)
	{
		cin >> M >> N >> K;

		int X, Y;
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;

			Adj[X][Y] = 1;
		}

		int Cnt = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!IsVisited[i][j] && Adj[i][j] == 1)
				{
					DFS(i, j, M, N);
				}

				if (Depth > 0)
				{
					Cnt++;
				}

				Depth = 0;
			}
		}

		cout << Cnt << "\n";

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				Adj[i][j] = 0;
				IsVisited[i][j] = false;
			}
		}
		Cnt = 0;

		index++;
	}

	return 0;
}
