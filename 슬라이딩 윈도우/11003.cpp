#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, L;
	cin >> N >> L;

	deque<pair<int, int>> Numbers;
	int Number;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Number;

		Numbers.push_back(pair<int, int>(i, Number));

		if (Numbers.front().first <= i - L)
		{
			Numbers.pop_front();

		}

		if (Numbers.size() > 1)
		{

			while(Numbers.size() != 1)
			{
				if (Numbers[Numbers.size()-2].second >= Numbers.back().second)
				{
					index = Numbers.size() - 2;
					Numbers.erase(Numbers.begin() + index);
				}
				else
				{
					break;
				}
			}

		}

		cout << Numbers.front().second << " ";

	}
	
	return 0;
}

