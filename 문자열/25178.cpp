#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool IsVowel(char c);
bool CheckSameVector(const vector<char>& s1, const vector<char>& s2);
bool CheckVowelMap(const map<char, int>& s1, const map<char, int>& s2);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<char> s1ConsonantsVector;
    vector<char> s2ConsonantsVector;

    map<char, int> s1VowelMap;
    map<char, int> s2VowelMap;

    string s1, s2;
    cin >> s1 >> s2;

    if (s1[0] != s2[0] || s1[n - 1] != s2[n - 1])
    {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (IsVowel(s1[i]))
        {
            s1VowelMap[s1[i]]++;
        }
        else
        {
            s1ConsonantsVector.push_back(s1[i]);
        }

        if (IsVowel(s2[i]))
        {
            s2VowelMap[s2[i]]++;
        }
        else
        {
            s2ConsonantsVector.push_back(s2[i]);
        }
    }

    if (CheckSameVector(s1ConsonantsVector, s2ConsonantsVector) &&
        CheckVowelMap(s1VowelMap, s2VowelMap))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}

bool IsVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }

    return false;
}

bool CheckSameVector(const vector<char>& s1, const vector<char>& s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}

bool CheckVowelMap(const map<char, int>& s1, const map<char, int>& s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    auto it1 = s1.begin();
    auto it2 = s2.begin();

    for (; it1 != s1.end() && it2 != s2.end(); it1++, it2++)
    {
        if (it1->first != it2->first)
        {
            return false;
        }

        if (it1->second != it2->second)
        {
            return false;
        }
    }

    return true;
}
