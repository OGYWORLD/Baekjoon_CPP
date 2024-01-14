#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

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

	stack<char> Bracket;

	string Sentence;
	int Size;
	int Flag = 0;
	for (;;)
	{
		getline(cin, Sentence, '\n');

		if (Sentence[0] == '.')
		{
			break;
		}
		Size = Sentence.size();

		for (int j = 0; j < Size; j++)
		{
			if (Sentence[j] == '(')
			{
				Bracket.push('(');
			}
			else if (Sentence[j] == '[')
			{
				Bracket.push('[');
			}
			else if(Sentence[j] == ')' || Sentence[j] == ']')
			{
				if (Bracket.size() < 1)
				{
					Flag = 1;
					break;
				}

				if ((Sentence[j] == ')' && Bracket.top() == '[') || ((Sentence[j] == ']' && Bracket.top() == '(')))
				{
					Flag = 1;
					break;
				}

				Bracket.pop();
			}
		}

		if (Flag != 1 && Bracket.size() == 0)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}

		Flag = 0;
		StackClear(Bracket);
		Sentence = "";
		
	}
	
	return 0;
}

