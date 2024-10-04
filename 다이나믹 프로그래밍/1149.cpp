#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Cost
{
	int r;
	int g;
	int b;
};
  

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Cost> v(n+1);
	v[0] = { 0, 0, 0 };

	int result = 10000000;
	int r, g, b;
	for (int i = 1; i <= n; i++)
	{
		cin >> r >> g >> b;

		v[i].r = min(v[i - 1].g, v[i - 1].b) + r;
		v[i].g = min(v[i - 1].r, v[i - 1].b) + g;
		v[i].b = min(v[i - 1].r, v[i - 1].g) + b;
	}


	if (result > v[n].r) result = v[n].r;
	if (result > v[n].g) result = v[n].g;
	if (result > v[n].b) result = v[n].b;

	cout << result;

	return 0;
}

