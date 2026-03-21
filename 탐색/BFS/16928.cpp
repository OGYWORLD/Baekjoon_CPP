#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int minRoll = 101;

queue<pair<int, int>> moveQueue;

vector<bool> isVisited(101, false);
map<int, int> ladder;
map<int, int> snake;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ladder[a] = b;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        snake[a] = b;
    }

    moveQueue.push(make_pair(1, 0));
    while (!moveQueue.empty())
    {
        int currentNumber = moveQueue.front().first;
        int currentCount = moveQueue.front().second;
        moveQueue.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nextNumber = currentNumber + i;
            if (ladder.find(nextNumber) != ladder.end())
            {
                nextNumber = ladder[nextNumber];
            }

            if (snake.find(nextNumber) != snake.end())
            {
                nextNumber = snake[nextNumber];
            }

            if (nextNumber == 100)
            {
                if (currentCount + 1 < minRoll)
                {
                    minRoll = currentCount + 1;
                    break;
                }
            }
            else if (nextNumber > 100)
            {
                break;
            }
            else
            {
                if (!isVisited[nextNumber])
                {
                    isVisited[nextNumber] = true;
                    moveQueue.push(make_pair(nextNumber, currentCount + 1));
                }
            }
        }
    }
    
    cout << minRoll;

    return 0;
}
