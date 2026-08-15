#include <iostream>
#include <vector>
using namespace std;
int dfs(int node , vector<int> adj[],vector<int> &vis,int parent)
{
    vis[node]=1;
    int x=0;
    for(auto it : adj[node])
    {
        if(vis[it]!=1)
        {
            if (dfs(it, adj, vis, node))
            return 1;
        }
        else
        {
           if(it!=parent && it!=-1)
           x=1;
        }
    }
    return x;
    
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> adj[n+1];
    int u,v;

    for(int i=0 ; i<m ; i++)
    {
       cin >> u >> v ;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vector <int> vis(n+1,0);
    int cycle=0;
    for(int j=1;j<n;j++)
    {
        if(dfs(j,adj,vis,-1)==1)
        cycle=1;
    }
    cout << cycle;
}