#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	deque<int> Ballon;
	vector<int> PaperVector;
	int PaperNumber;
	for (int i = 1; i <= N; i++)
	{
		cin >> PaperNumber;
		Ballon.push_back(i);
		PaperVector.push_back(PaperNumber);
	}

	Ballon.pop_front();
	cout << "1 ";
	int Paper = PaperVector[0];
	while (1)
	{
		if (Ballon.size() == 1)
		{
			cout << Ballon.front();
			break;
		}
		
		if (Paper > 0)
		{
			for (int i = 0; i < Paper-1; i++)
			{
				Ballon.push_back(Ballon.front());
				Ballon.pop_front();
			}

			Paper = PaperVector[Ballon.front()-1];
			cout << Ballon.front() << " ";
			Ballon.pop_front();
		}
		else
		{
			for (int i = 0; i < -Paper - 1; i++)
			{
				Ballon.push_front(Ballon.back());
				Ballon.pop_back();
			}

			Paper = PaperVector[Ballon.back() - 1];
			cout << Ballon.back() << " ";
			Ballon.pop_back();
		}
	}
	

	return 0;
}
