#include <iostream>

using namespace std;

struct Info
{
    int seed = 0;
    int cnt = 0;
};

void BuyJuneWay(Info& info, int cost);
void BuySungWay(Info& info, bool isIncrease, int cost);
void BuyAll(Info& info, int cost);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int seed;
    cin >> seed;

    const int TOTAL_DAY = 14;

    Info juneInfo;
    Info sungInfo;

    juneInfo.seed = seed;
    sungInfo.seed = seed;

    bool isIncrease = false;
    int conditionCnt = 0;
    int todayCost;
    int preCost;
    for (int i = 0; i < TOTAL_DAY; i++)
    {
        cin >> todayCost;

        BuyJuneWay(juneInfo, todayCost);

        if (i != 0)
        {
            if (todayCost > preCost)
            {
                if (!isIncrease)
                {
                    conditionCnt = 0;
                }
                isIncrease = true;
                conditionCnt++;
            }
            else if (todayCost < preCost)
            {
                if (isIncrease)
                {
                    conditionCnt = 0;
                }
                isIncrease = false;
                conditionCnt++;
            }
            else
            {
                conditionCnt = 0;
            }
        }

        if (conditionCnt >= 3)
        {
            BuySungWay(sungInfo, isIncrease, todayCost);
        }

        preCost = todayCost;
    }

    int juneFinal = juneInfo.cnt * todayCost + juneInfo.seed;
    int sungFinal = sungInfo.cnt * todayCost + sungInfo.seed;
    if (juneFinal > sungFinal)
    {
        cout << "BNP";
    }
    else if (juneFinal < sungFinal)
    {
        cout << "TIMING";
    }
    else
    {
        cout << "SAMESAME";
    }

    return 0;
}

void BuyJuneWay(Info& info, int cost)
{
    if (info.seed >= cost)
    {
        BuyAll(info, cost);
    }
}

void BuySungWay(Info& info, bool isIncrease, int cost)
{
    if (!isIncrease)
    {
        BuyAll(info, cost);
    }
    else
    {
        info.seed += (info.cnt * cost);
        info.cnt = 0;
    }
}

void BuyAll(Info& info, int cost)
{
    int buyCnt = info.seed / cost;
    info.cnt += buyCnt;
    info.seed -= buyCnt * cost;
}
