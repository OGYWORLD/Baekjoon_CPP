#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<char> Line;

void Cantor(int l, int srt, int d, int td)
{
	if (d == td)
	{
		
	}
	else
	{
		int Div = l / 3;
		for (int i = srt+Div; i < srt+Div * 2; i++)
		{
			Line[i] = ' ';
		}

		for (int i = srt+1; i < srt+l; i+=Div)
		{
			if (Line[i - 1] == '-' && Line[i] == '-')
			{
				Cantor(Div, i-1, d+1, td);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	while (!(cin >> N).eof())
	{
		int TotalLen = pow(3, N);

		for (int i = 0; i < TotalLen; i++)
		{
			Line.push_back('-');
		}

		Cantor(TotalLen, 0, 0, TotalLen / 3);

		for (int i = 0; i < Line.size(); i++)
		{
			cout << Line[i];
		}
		cout << "\n";

		Line.clear();
	}

	return 0;
}