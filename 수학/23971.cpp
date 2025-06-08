// 백준 23971 ZOAC 4
#include <iostream>

using namespace std;

int Calcul(int hw, int nm);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int a = Calcul(h, n);
    int b = Calcul(w, m);

    cout << a * b;

    return 0;
}

int Calcul(int hw, int nm)
{
    return hw % (nm + 1) == 0 ? hw / (nm + 1) : hw / (nm + 1) + 1;
}
