#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int Number;
	stack<int> S;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		S.push(Number);
	}

	vector<int> Result(N, -1);

	if (N == 1)
	{
		cout << "-1";
	}
	else
	{
		int Now;
		int index = 1;
		int index2 = 0;
		while (1)
		{
			Now = S.top();
			S.pop();
			if (S.size() == 0)
			{
				break;
			}

			if (Now > S.top())
			{
				Result[index] = Now;
				index++;
			}
			else
			{
				index2 = index - 1;
				int j = 0;
				while (1)
				{
					if (S.top() < Result[index2 - j])
					{
						Result[index] = Result[index2 - j];
						index++;
						break;
					}
					if (Result[index2 - j] == -1)
					{
						Result[index] = -1;
						index++;
						break;
					}
					else
					{
						j++;
					}
				}
			}

		}

		for (int i = Result.size() - 1; i > -1; i--)
		{
			cout << Result[i] << " ";
		}
	}
	


	return 0;
}
