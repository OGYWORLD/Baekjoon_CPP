#include <iostream>
#include <vector>

using namespace std;

static vector<int> People;

int FindRepNode(int Node)
{
	if (Node == People[Node])
	{
		return Node;
	}
	else
	{
		return People[Node] = FindRepNode(People[Node]);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	People.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		People[i] = i;
	}

	int TrueNum;
	cin >> TrueNum;

	vector<int> TruePeople(TrueNum);
	int TrueRep;
	for (int i = 0; i < TrueNum; i++)
	{
		cin >> TruePeople[i];

		if (i == 0)
		{
			TrueRep = People[TruePeople[0]];
		}
		else
		{
			int SetTrue = FindRepNode(TruePeople[i]);

			People[SetTrue] = TrueRep;
		}
	}

	int index = 0;
	int PartyPeopleNum, PartyPeople, BeforePartyPeople;
	vector <vector<int>> PartyList(M);
	while (index < M)
	{
		cin >> PartyPeopleNum;

		cin >> PartyPeople;
		PartyList[index].push_back(PartyPeople);

		BeforePartyPeople = PartyPeople;
		for (int i = 1; i < PartyPeopleNum; i++)
		{
			cin >> PartyPeople;
			PartyList[index].push_back(PartyPeople);

			int BR = FindRepNode(BeforePartyPeople);
			int NR = FindRepNode(PartyPeople);

			if (BR != NR)
			{
				People[BR] = NR;
			}
		}

		index++;
	}

	index = M-1;
	while (index > -1)
	{

		BeforePartyPeople = PartyList[index][0];
		for (int i = 1; i < PartyList[index].size(); i++)
		{
			int BR = FindRepNode(BeforePartyPeople);
			int NR = FindRepNode(PartyList[index][i]);

			if (BR != NR)
			{
				People[BR] = NR;
			}
		}

		index--;
	}

	bool bIsCntParty = true;
	int Cnt = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < PartyList[i].size(); j++)
		{
			for (int k = 0; k < TrueNum; k++)
			{
				if (People[PartyList[i][j]] == People[TruePeople[k]])
				{
					bIsCntParty = false;
					break;
				}
			}

			if (!bIsCntParty)
			{
				break;
			}
		}

		if (bIsCntParty)
		{
			Cnt++;
		}

		bIsCntParty = true;
	}

	cout << Cnt;


	return 0;
}
