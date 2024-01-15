#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int Order;
	deque<int> OrderDeque;
	for (int i = 0; i < N; i++)
	{
		cin >> Order;
		OrderDeque.push_back(Order);
	}

	deque<int> ResultDeque;
	for (int i = 1; i <= N; i++)
	{
		if (OrderDeque.back() == 1)
		{
			OrderDeque.pop_back();
			ResultDeque.push_front(i);
		}

		else if (OrderDeque.back() == 2)
		{
			OrderDeque.pop_back();
			ResultDeque.insert(ResultDeque.begin() + 1, i);
		}

		else if (OrderDeque.back() == 3)
		{
			OrderDeque.pop_back();
			ResultDeque.push_back(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ResultDeque[i] << " ";
	}

	
	return 0;
}