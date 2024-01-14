#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N;
	cin >> K;

	queue<int> People;
	for (int i = 1; i <= N; i++)
	{
		People.push(i);
	}

	cout << "<";
	int index = 0;
	while (1)
	{
		if (index == K - 1)
		{
			if (People.size() == 1)
			{
				cout << People.front() << ">";
				break;
			}
			else
			{
				cout << People.front() << ", ";
			}
			People.pop();
			index = 0;
		}
		else
		{
			People.push(People.front());
			People.pop();
			index++;
		}
	}

	return 0;
}

