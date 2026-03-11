#include <iostream>
#include <vector>

using namespace std;

vector<long long> country;
vector<long long> weight;

const long long MAX_PRICE = 10000000001LL;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    country.resize(n);
    weight.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> country[i];
    }

    long long min = MAX_PRICE;
    long long result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (min > country[i])
        {
            min = country[i];
        }
        result += min * weight[i];
    }

    cout << result;

    return 0;
}