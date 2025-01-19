#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        int expect = -1;
        char weather = ' ';
        for (int j = 0; j < w; j++)
        {
            cin >> weather;

            if (weather == 'c')
            {
                expect = 0;
            }
            else
            {
                if (expect != -1)
                {
                    expect++;
                }
            }

            cout << expect << " ";
        }
        
        cout << "\n";
    }


    return 0;
}