#include <iostream>
#include <vector>

using namespace std;

void FindRelationDFS(vector<vector<int>>& adj, vector<bool>& isVisited, int destination, int node, int depth, bool& isFind);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> isVisited(n + 1, false);

    int person1, person2;
    cin >> person1 >> person2;

    int relationNum;
    cin >> relationNum;

    int givenRelation1, givenRelation2;
    for (int i = 0; i < relationNum; i++)
    {
        cin >> givenRelation1 >> givenRelation2;
        adj[givenRelation1].push_back(givenRelation2);
        adj[givenRelation2].push_back(givenRelation1);
    }

    bool isFind = false;
    FindRelationDFS(adj, isVisited, person2, person1, 0, isFind);

    if (!isFind)
    {
        cout << "-1";
    }
    
    return 0;
}

void FindRelationDFS(vector<vector<int>>& adj, vector<bool>& isVisited, int destination, int node, int depth, bool& isFind)
{
    if (node == destination)
    {
        isFind = true;
        cout << depth;
        return;
    }

    isVisited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!isVisited[adj[node][i]])
        {
            FindRelationDFS(adj, isVisited, destination, adj[node][i], depth + 1, isFind);
            if (isFind)
            {
                return;
            }
        }
    }
}
