#include <iostream>

using namespace std;

int n, r, c;

void DivideMatrix(int n, int r, int c, int cnt);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> r >> c;

    DivideMatrix(n, r, c, 0);

    return 0;
}

void DivideMatrix(int n, int r, int c, int cnt)
{
    if (n == 0)
    {
        cout << cnt;
        return;
    }
    
    int half = 1 << (n - 1);
    int block = half * half;

    int rowBit = (r >= half) ? 1 : 0;
    int colBit = (c >= half) ? 1 : 0;
    int quad = rowBit * 2 + colBit;

    cnt += quad * block;

    if (r >= half) r -= half;
    if (c >= half) c -= half;

    DivideMatrix(n - 1, r, c, cnt);
}
