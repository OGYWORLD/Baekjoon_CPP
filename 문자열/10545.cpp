#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, char> convertNumberMap;
map<char, string> makeNumberMap;

void MakeNumber();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    MakeNumber();

    int n;
    const int TOTAL_NUM = 10;
    for (int i = 1; i < TOTAL_NUM; i++)
    {
        cin >> n;
        convertNumberMap[n] = i + '0';
    }

    cin.ignore();
    string targetString;
    getline(cin, targetString);

    string temp = "";
    temp += makeNumberMap[targetString[0]];
    for (int i = 1; i < targetString.size(); i++)
    {
        string pre = makeNumberMap[targetString[i - 1]];
        string post = makeNumberMap[targetString[i]];

        if (pre[pre.size() - 1] == post[0])
        {
            temp += "#";
        }

        temp += makeNumberMap[targetString[i]];
    }

    string result = "";
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] != '#')
        {
            result += convertNumberMap[temp[i] - '0'];
        }
        else
        {
            result += '#';
        }
    }

    cout << result;

    return 0;
}

void MakeNumber()
{
    makeNumberMap[' '] = "1";

    makeNumberMap['a'] = "2";
    makeNumberMap['b'] = "22";
    makeNumberMap['c'] = "222";

    makeNumberMap['d'] = "3";
    makeNumberMap['e'] = "33";
    makeNumberMap['f'] = "333";

    makeNumberMap['g'] = "4";
    makeNumberMap['h'] = "44";
    makeNumberMap['i'] = "444";

    makeNumberMap['j'] = "5";
    makeNumberMap['k'] = "55";
    makeNumberMap['l'] = "555";

    makeNumberMap['m'] = "6";
    makeNumberMap['n'] = "66";
    makeNumberMap['o'] = "666";
    
    makeNumberMap['p'] = "7";
    makeNumberMap['q'] = "77";
    makeNumberMap['r'] = "777";
    makeNumberMap['s'] = "7777";

    makeNumberMap['t'] = "8";
    makeNumberMap['u'] = "88";
    makeNumberMap['v'] = "888";

    makeNumberMap['w'] = "9";
    makeNumberMap['x'] = "99";
    makeNumberMap['y'] = "999";
    makeNumberMap['z'] = "9999";
}
