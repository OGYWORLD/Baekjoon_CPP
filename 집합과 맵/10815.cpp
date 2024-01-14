#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>


int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::map<int, int> SGCard;

	int card;
	for (int i = 0; i < n; i++)
	{
		std::cin >> card;
		SGCard.insert(std::pair<int, int>(card, 1));
	}

	int m;
	std::cin >> m;

	for (int i = 0; i < m; i++)
	{
		std::cin >> card;
		if (SGCard.find(card) != SGCard.end())
		{
			std::cout << 1 << " ";
		}
		else
		{
			std::cout << 0 << " ";
		}
	}

	return 0;
}