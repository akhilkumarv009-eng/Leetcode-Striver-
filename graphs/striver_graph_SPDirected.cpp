#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> topoSort(int n,vector<pair<int,int>> adj[])
{
    vector<int> top;
    queue <int> q;
    vector<int> indegree(n);
    for(int i=0;i<n;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it.first]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        top.push_back(node);
        q.pop();
        for(auto it : adj[node])
        {
            indegree[it.first]--;
            if(indegree[it.first]==0)
            {
                q.push(it.first);
            }
        }
    }
    return top;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    int u,v,wt;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }
    vector <int> topo = topoSort(n,adj);
    vector<int> dis(n,-1);
    int src=0;
    dis[src]=0;
    for(auto it : topo)
    {
        if(dis[it]==-1)continue;
        for(auto node : adj[it])
        {
            int u = it;
            int v = node.first;
            int wt= node.second;

           if(dis[v]==-1)
           dis[v]=dis[u]+wt;

           else
           dis[v]=min(dis[u]+wt,dis[v]);
        }
    }
    for(auto it : dis)
    {
        cout << it << " ";
    }

}
