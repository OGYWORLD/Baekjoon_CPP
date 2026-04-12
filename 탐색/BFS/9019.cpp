#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int D(int n);
int S(int n);
int L(int n);
int R(int n);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n1, n2;
    for (int i = 0; i < t; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        vector<bool> visited(10000, false);
        vector<int> prev(10000, -1);
        vector<char> how(10000);

        queue<int> q;
        q.push(n1);
        visited[n1] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            if (current == n2)
            {
                break;
            }

            int nextD = D(current);
            int nextS = S(current);
            int nextL = L(current);
            int nextR = R(current);

            if (!visited[nextD])
            {
                visited[nextD] = true;
                prev[nextD] = current;
                how[nextD] = 'D';
                q.push(nextD);
            }

            if (!visited[nextS])
            {
                visited[nextS] = true;
                prev[nextS] = current;
                how[nextS] = 'S';
                q.push(nextS);
            }

            if (!visited[nextL])
            {
                visited[nextL] = true;
                prev[nextL] = current;
                how[nextL] = 'L';
                q.push(nextL);
            }

            if (!visited[nextR])
            {
                visited[nextR] = true;
                prev[nextR] = current;
                how[nextR] = 'R';
                q.push(nextR);
            }
        }

        string result = "";
        int current = n2;

        while (current != n1)
        {
            result += how[current];
            current = prev[current];
        }

        reverse(result.begin(), result.end());
        cout << result << "\n";
    }

    return 0;
}

int D(int n)
{
    return (n * 2) % 10000;
}

int S(int n)
{
    return n == 0 ? 9999 : n - 1;
}

int L(int n)
{
    return (n % 1000) * 10 + n / 1000;
}

int R(int n)
{
    return (n % 10) * 1000 + n / 10;
}