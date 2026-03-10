#include <iostream>
#include <vector>

using namespace std;

void Backtracking(vector<int>& v, vector<bool>& isVisited, const int n);
void PrintVector(const vector<int>& v);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;
    vector<bool> isVisited(n + 1, false);

    Backtracking(v, isVisited, n);

    return 0;
}

void Backtracking(vector<int>& v, vector<bool>& isVisited, const int n)
{
    if (v.size() == n)
    {
        PrintVector(v);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            v.push_back(i);
            Backtracking(v, isVisited, n);
            v.pop_back();
            isVisited[i] = false;
        }
    }
}

void PrintVector(const vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
