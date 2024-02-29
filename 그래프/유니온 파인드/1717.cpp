#include <iostream>
#include <vector>


using namespace std;

static vector<int> Ar;

int FindRepNode(int NodeValue)
{
	if (NodeValue == Ar[NodeValue])
	{
		return NodeValue;
	}
	else
	{
		return Ar[NodeValue] = FindRepNode(Ar[NodeValue]);
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		Ar.push_back(i);
	}

	int Order, a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> Order >> a >> b;

		if (Order == 0)
		{
			int ARepNode = FindRepNode(a);
			int BRepNode = FindRepNode(b);

			if (ARepNode != BRepNode)
			{
				Ar[BRepNode] = ARepNode;
			}
		}
		else
		{
			int ARepNode = FindRepNode(a);
			int BRepNode = FindRepNode(b);

			if (ARepNode == BRepNode)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}
