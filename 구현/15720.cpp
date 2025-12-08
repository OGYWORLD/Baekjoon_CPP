#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> menus(3);
    int min = 1001;
    for(int i = 0; i < menus.size(); i++)
    {
        cin >> menus[i];
        if (menus[i] < min) min = menus[i];
    }

    vector<vector<int>> prices;
    for (int i = 0; i < menus.size(); i++)
    {
        int price;
        vector<int> temp;
        for (int j = 0; j < menus[i]; j++)
        {
            cin >> price;
            temp.push_back(price);
        }
        prices.push_back(temp);
    }

    for (int i = 0; i < prices.size(); i++)
    {
        sort(prices[i].begin(), prices[i].end(), greater<int>{});
    }

    int originPrice = 0, discountPrice = 0;
    for (int i = 0; i < menus.size(); i++)
    {
        for (int j = 0; j < menus[i]; j++)
        {
            if (j < min)
            {
                discountPrice += (prices[i][j] * 0.9);
            }
            else
            {
                discountPrice += prices[i][j];
            }

            originPrice += prices[i][j];
        }
    }

    cout << originPrice << "\n" << discountPrice;

    return 0;
}