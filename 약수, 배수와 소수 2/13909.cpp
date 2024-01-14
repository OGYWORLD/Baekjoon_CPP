#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int Cnt = 0;
	for (int i = 1; i*i <= T; i++)
	{
		Cnt++;
	}

	cout << Cnt;

	return 0;
}