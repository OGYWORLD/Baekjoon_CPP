#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int S, P;
	cin >> S >> P;

	vector<char> DNA(0, S);
	char DNAProtein;
	for (int i = 0; i < S; i++)
	{
		cin >> DNAProtein;
		DNA.push_back(DNAProtein);
	}

	int A_Number, C_Number, G_Number, T_Number;

	cin >> A_Number >> C_Number >> G_Number >> T_Number;

	int Cnt = 0;
	int A_Check = 0, C_Check = 0, G_Check = 0, T_Check = 0;

	for (int i = 0; i < S; i++)
	{
		if (DNA[i] == 'A')
		{
			A_Check++;
		}
		else if (DNA[i] == 'C')
		{
			C_Check++;
		}
		else if (DNA[i] == 'G')
		{
			G_Check++;
		}
		else
		{
			T_Check++;
		}

		if (i >= P-1)
		{
			if (A_Check >= A_Number && C_Check >= C_Number && G_Check >= G_Number && T_Check >= T_Number)
			{
				Cnt++;
			}

			if (DNA[i - P + 1] == 'A')
			{
				A_Check--;
			}
			else if (DNA[i - P + 1] == 'C')
			{
				C_Check--;
			}
			else if (DNA[i - P + 1] == 'G')
			{
				G_Check--;
			}
			else
			{
				T_Check--;
			}


		}

	}

	cout << Cnt;
	
	return 0;
}

