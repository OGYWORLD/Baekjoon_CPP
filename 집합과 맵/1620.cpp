#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int PokemonListNumber, QuestionListNumber;

	map<string, string> ListKeyNumber;
	map<string, string> ListKeyName;

	cin >> PokemonListNumber;
	cin >> QuestionListNumber;

	string Name;
	for (int i = 0; i < PokemonListNumber; i++)
	{
		cin >> Name;
		ListKeyNumber.insert(pair<string, string>(to_string(i), Name));
		ListKeyName.insert(pair<string, string>(Name, to_string(i)));
	}

	string Question;
	string KeyNumber;
	int ValueNumber;
	for (int i = 0; i < QuestionListNumber; i++)
	{
		cin >> Question;

		// 해당 입력이 숫자인지 문자열인지 확인
		if (48 <= int(Question.at(0)) && int(Question.at(0)) <= 57)
		{
			// 번호를 입력 받았을 때 = Key를 입력 받았을 때
			KeyNumber = to_string(stoi(Question) - 1);

			if (ListKeyNumber.find(KeyNumber) != ListKeyNumber.end())
			{
				cout << ListKeyNumber.find(KeyNumber)->second << "\n";
			}
		}
		else
		{
			// 이름을 입력 받았을 때 = Value를 입력 받았을 때
			if (ListKeyName.find(Question) != ListKeyName.end())
			{
				ValueNumber = stoi(ListKeyName.find(Question)->second);
				cout << ValueNumber+1 << "\n";
			}
		}
	}

	return 0;
}