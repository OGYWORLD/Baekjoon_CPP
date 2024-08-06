#include <iostream>
#include <vector>

using namespace std;

vector<char> info(3);
vector<pair<int,int>> tree(27, pair<int,int>(0, 0));

int n;

void Preorder(int nodeIdx);
void Inorder(int nodeIdx);
void Postorder(int nodeIdx);


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	int index = 0;
	while (index < n)
	{
		cin >> info[0] >> info[1] >> info[2];
		if (info[1] != '.')
		{
			tree[info[0] - 64].first = (info[1] - 64);
		}
		if (info[2] != '.')
		{
			tree[info[0] - 64].second = (info[2] - 64);
		}

		index++;
	}

	Preorder(1);
	cout << "\n";
	Inorder(1);
	cout << "\n";
	Postorder(1);

	return 0;
}

void Preorder(int nodeIdx)
{
	if (nodeIdx == 0)
	{
		return;
	}

	cout << (char)(nodeIdx + 64);

	Preorder(tree[nodeIdx].first); // left search

	Preorder(tree[nodeIdx].second); // right search
}

void Inorder(int nodeIdx)
{
	if (nodeIdx == 0)
	{
		return;
	}

	Inorder(tree[nodeIdx].first); // left search

	cout << (char)(nodeIdx + 64);

	Inorder(tree[nodeIdx].second); // right search
}

void Postorder(int nodeIdx)
{
	if (nodeIdx == 0)
	{
		return;
	}

	Postorder(tree[nodeIdx].first); // left search

	Postorder(tree[nodeIdx].second); // right search

	cout << (char)(nodeIdx + 64);
}