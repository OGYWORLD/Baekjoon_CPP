#include <iostream>
#include <set>

using namespace std;

bool CheckIsCheese(string food);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int QUATTRO_CHEESE = 4;

    int n;
    cin >> n;

    string food;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        cin >> food;
        if (CheckIsCheese(food))
        {
            s.insert(food);
        }
    }

    if (s.size() >= QUATTRO_CHEESE)
    {
        cout << "yummy";
    }
    else
    {
        cout << "sad";
    }

    return 0;
}

bool CheckIsCheese(string food)
{
    const int CHEESE = 6;
    string cheese = "Cheese";

    int len = food.size();
    if (len < CHEESE) return false;

    bool isEndByCheese = true;
    for (int i = len - CHEESE; i < len; i++)
    {
        if (food[i] != cheese[i - (len - CHEESE)])
        {
            isEndByCheese = false;
        }
    }

    return isEndByCheese;
}