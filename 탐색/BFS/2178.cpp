#include <iostream>
#include <queue>

using namespace std;

bool IsVistied[101][101];


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	
	int N, M;
	cin >> N >> M;

	int Maze[101][101];

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			Maze[i][j] = s[j] - '0';
		}
	}

	queue<pair<int,int>> Visiting;
	Visiting.push(pair<int, int>(0, 0));
	IsVistied[0][0] = true;

	int x, y;
	while (Visiting.size() != 0)
	{
		//pop
		x = Visiting.front().first;
		y = Visiting.front().second;
		Visiting.pop();

		//check
		if (x == N - 1 && y == M - 1)
		{
			cout << Maze[x][y];
			break;
		}

		//push
		for (int k = 0; k < 4; k++)
		{
			if (dx[k] + x < 0 || dx[k] + x > N - 1 || dy[k] + y < 0 || dy[k] + y > M - 1)
			{
				continue;
			}
			else
			{
				if (!IsVistied[dx[k] + x][dy[k] + y] && Maze[dx[k] + x][dy[k] + y] != 0)
				{
					Visiting.push(pair<int, int>(dx[k] + x, dy[k] + y));
					IsVistied[dx[k] + x][dy[k] + y] = true;
					Maze[dx[k] + x][dy[k] + y] = Maze[x][y] + 1;
				}
			}
		}
	}


	return 0;
}