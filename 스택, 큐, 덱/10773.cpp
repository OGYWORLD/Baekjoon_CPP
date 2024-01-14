#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	int Number;
	stack<int> stack;
	for (int i = 0; i < K; i++)
	{
		cin >> Number;
		if (Number == 0)
		{
			stack.pop();
		}
		else
		{
			stack.push(Number);
		}
	}

	int Result = 0;
	int Size = stack.size();
	for (int i = 0; i < Size; i++)
	{
		Result += stack.top();
		stack.pop();
	}
	
	cout << Result;

	return 0;
}
