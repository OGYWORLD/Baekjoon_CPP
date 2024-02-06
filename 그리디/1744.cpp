#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<int> Q;
	int Number;
	int NegativeCnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;
		Q.push(Number);

		if (Number < 0)
		{
			NegativeCnt++;
		}
	}

	int Data1, Data2;
	int Result = 0;
	int flag = NegativeCnt % 2;
	int ChangeFlag = 0;
	while (Q.size() > 1)
	{
		Data1 = Q.top();
		Q.pop();
		Data2 = Q.top();
		Q.pop();

		if (Data1 < 0 && Data2 < 0)
		{
			ChangeFlag = 1;
			Q.push(Data1);
			Q.push(Data2);
			vector<int> V;
			if (flag == 1)
			{
				Result += Q.top();
				Q.pop();
				int S = Q.size();
				for (int i = 0; i < S; i++)
				{
					V.push_back(-Q.top());
					Q.pop();
				}
				for (int i = 0; i < S; i++)
				{
					Q.push(V[i]);
				}
			}
			else
			{
				int S = Q.size();
				for (int i = 0; i < S; i++)
				{
					V.push_back(-Q.top());
					Q.pop();
				}
				for (int i = 0; i < S; i++)
				{
					Q.push(V[i]);
				}
			}
			V.clear();
		}
		else if (Data1 > 0 && Data2 < 0)
		{
			Result += Data1;
			Q.push(Data2);
		}
		else if (Data1 == 0 && Data2 < 0)
		{
			if (flag == 0)
			{
				Q.push(Data2);
			}
			else
			{
				flag = 0;
			}
		}
		else if (Data1 == 0 && Data2 == 0)
		{
			if (flag == 1)
			{
				Q.push(Data2);
			}
		}
		else if (Data1 > 0 && Data2 == 0)
		{
			if (flag == 1)
			{
				Result += Data1;
				Q.push(Data2);
			}
			else
			{
				Result += Data1;
			}
		}
		else
		{
			if (ChangeFlag == 1)
			{
				Result += Data1 * Data2;
			}
			else if (Data2 == 1)
			{
				Result += Data1 + Data2;
			}
			else
			{
				Result += Data1 * Data2;
			}
		}
	}

	if (Q.size() > 0)
	{
		Result += Q.top();
	}

	cout << Result;


	return 0;
}