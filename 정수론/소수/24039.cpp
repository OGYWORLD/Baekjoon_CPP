#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    const int MAX_NUM = 10001;
    vector<bool> isPrimeVector(MAX_NUM, true);
    vector<int> primeVector;

    isPrimeVector[0] = false;
    isPrimeVector[1] = false;

    for (int i = 2; i * i < MAX_NUM; i++)
    {
        if (isPrimeVector[i])
        {
            for (int j = i * i; j < MAX_NUM; j += i)
            {
                isPrimeVector[j] = false;
            }
        }
    }

    for (int i = 2; i < MAX_NUM; i++)
    {
        if (isPrimeVector[i])
        {
            primeVector.push_back(i);
        }
    }

    int n;
    cin >> n;

    for (int i = 1; i < primeVector.size(); i++)
    {
        int temp = primeVector[i] * primeVector[i - 1];
        if (temp > n)
        {
            cout << temp;
            break;
        }
    }

    return 0;
}