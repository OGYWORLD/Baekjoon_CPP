#include <iostream>
#include <string>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	int Size = s.size();

	string N = "";
	int ResultSum = 0;
	int TempSum = 0;
	int flag = 0;

	for (int i = 0; i < Size; i++)
	{
		if (s[i] == '-' && flag == 0)
		{
			flag = 1;
			TempSum += stoi(N);
			ResultSum += TempSum;
			N = "";
		}
		else if (flag == 1 && s[i] != '-' && s[i] != '+')
		{
			N += s[i];
		}
		else if (flag == 1 && (s[i] == '-' || s[i] == '+'))
		{
			ResultSum -= stoi(N);
			N = "";
		}
		else if(flag == 0 && s[i] == '+')
		{
			TempSum += stoi(N);
			N = "";
		}
		else
		{
			N += s[i];
		}

		if (i == Size - 1)
		{
			if (flag == 0)
			{
				ResultSum += stoi(N);
				ResultSum += TempSum;
			}
			else
			{
				ResultSum -= stoi(N);
			}
		}
	}

	cout << ResultSum;

	return 0;
}
