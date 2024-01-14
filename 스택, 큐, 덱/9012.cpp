#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

void StackClear(stack<char>& s)
{
	int Size = s.size();
	for (int index = 0; index < Size; index++)
	{
		s.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<char> VPSCheck;

	int T;
	cin >> T;

	string PS;
	int Flag = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> PS;

		for (int j = 0; j < PS.size(); j++)
		{
			if (PS[j] == '(')
			{
				VPSCheck.push('(');
			}
			else
			{
				if (VPSCheck.size() < 1)
				{
					Flag = 1;
					break;
				}

				VPSCheck.pop();
			}
		}

		if (Flag != 1 && VPSCheck.size() == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}

		Flag = 0;
		StackClear(VPSCheck);
		
	}
	
	return 0;
}
