#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

void PrintStack(stack<int> s, string n)
{
	cout << n << " Stack Print=============\n";
	int Size = s.size();
	for (int index = 0; index < Size; index++)
	{
		cout << s.top() << "\n";
		s.pop();
	}
	cout << "================\n";

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	stack<int> GetLine;
	stack<int> PresentLine;
	stack<int> TempLine;
	int Order;
	for (int i = 0; i < N; i++)
	{
		cin >> Order;
		GetLine.push(Order);
	}

	for (int i = 0; i < N; i++)
	{
		PresentLine.push(GetLine.top());
		GetLine.pop();
	}

	int LoopIndex = 0;
	int TotalWorkingCount = 0;
	int NowNumber = 1;
	while (1)
	{
		if (PresentLine.size() == 0 && TempLine.size() == 0)
		{
			cout << "Nice";
			break;
		}

		if (LoopIndex > TotalWorkingCount)
		{
			cout << "Sad";
			break;
		}

		if (PresentLine.size() != 0 && PresentLine.top() == NowNumber)
		{
			PresentLine.pop();
			NowNumber++;
			TotalWorkingCount++;
		}
		else if (TempLine.size() != 0 && TempLine.top() == NowNumber)
		{
			TempLine.pop();
			NowNumber++;
			TotalWorkingCount++;
		}
		else if(PresentLine.size() != 0)
		{
			TempLine.push(PresentLine.top());
			PresentLine.pop();
			TotalWorkingCount++;
		}

		LoopIndex++;
	}
	
	return 0;
}

