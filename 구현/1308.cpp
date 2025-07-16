#include <iostream>

using namespace std;

int year1, m1, d1, y2, m2, d2;

int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };

void DDayCalculator();
void DaysCalculator(int year);

enum eMonths
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    Max
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> year1 >> m1 >> d1 >> y2 >> m2 >> d2;

    DDayCalculator();

    return 0;
}

void DDayCalculator()
{
    if ((y2 - year1 > 1000) ||
        (y2 - year1 == 1000 && m2 > m1) ||
        (y2 - year1 == 1000 && m2 == m1 && d2 >= d1))
    {
        cout << "gg";
    }
    else
    {
        int result = 0;
        if (year1 == y2)
        {
            DaysCalculator(year1);

            if (m1 == m2)
            {
                result += d2 - d1;
            }
            else
            {
                for (int i = m1 + 1; i < m2; i++)
                {
                    result += days[i];
                }

                result += days[m1] - d1;
                result += d2;
            }
        }
        else
        {
            DaysCalculator(year1);

            result += days[m1] - d1;
            for (int i = m1 + 1; i < eMonths::Max; i++)
            {
                result += days[i];
            }

            for (int i = year1 + 1; i < y2; i++)
            {
                DaysCalculator(i);

                for (int i = eMonths::January; i < eMonths::Max; i++)
                {
                    result += days[i];
                }
            }

            DaysCalculator(y2);
            for (int i = eMonths::January; i < m2; i++)
            {
                result += days[i];
            }

            result += d2;
        }

        cout << "D-" << result;
    }
}

void DaysCalculator(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days[eMonths::February] = 29;
    }
    else
    {
        days[eMonths::February] = 28;
    }
}
