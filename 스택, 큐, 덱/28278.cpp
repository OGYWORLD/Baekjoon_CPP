#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> stack;

	
	int N;
	cin >> N;

	int StackOrder;
	int PushNumber;
	int TopTemp;
	for (int i = 0; i < N; i++)
	{
		cin >> StackOrder;

		// 1: push
		if (StackOrder == 1)
		{
			cin >> PushNumber;
			stack.push(PushNumber);
		}

		// 2: top print and delete
		if (StackOrder == 2)
		{
			if (stack.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				TopTemp = stack.top();
				stack.pop();
				cout << TopTemp << "\n";
			}
		}

		// 3: size
		if (StackOrder == 3)
		{
			cout << stack.size() << "\n";
		}

		// 4: empty check
		if (StackOrder == 4)
		{
			if (stack.size() < 1)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}

		// 5: print top
		if (StackOrder == 5)
		{
			if (stack.size() < 1)
			{
				cout << "-1\n";
			}
			else
			{
				cout << stack.top() << "\n";
			}
		}
	}
	
	return 0;
}