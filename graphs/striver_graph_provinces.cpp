#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &vis, int node, vector<int> adj[])
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(vis, it, adj);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected.size();

    // Create adjacency list
    vector<int> adj[V];

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> vis(V, 0);
    int count = 0;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(vis, i, adj);
        }
    }

    return count;
}

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> isConnected(V, vector<int>(V));

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> isConnected[i][j];
        }
    }

    cout << "Number of Provinces = " << findCircleNum(isConnected);

    return 0;
}