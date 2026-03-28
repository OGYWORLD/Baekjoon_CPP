#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long b;
    int n, m;
    cin >> b >> n >> m;

    unordered_map<string, long long> priceMap;

    string item;
    long long price;
    for (int i = 0; i < n; i++)
    {
        cin >> item >> price;
        priceMap[item] = price;
    }

    long long neededPrice = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> item;
        neededPrice += priceMap[item];
    }

    if (neededPrice <= b)
    {
        cout << "acceptable";
    }
    else
    {
        cout << "unacceptable";
    }

    return 0;
}