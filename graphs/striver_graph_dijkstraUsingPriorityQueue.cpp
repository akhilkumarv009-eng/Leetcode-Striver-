#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int u,v,wt;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
       cin >> u >> v >>wt;
       adj[u].push_back({v,wt});
       adj[v].push_back({u,wt});

    }
    int src=0;
    vector<int> dis(n,1e9);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
       int node = pq.top().second;
       int distance=pq.top().first;
       pq.pop();
       for(auto it: adj[node])
       {
           int v=it.first;
           int wt=it.second;
           if(distance+wt < dis[v])
           {
            dis[v]=distance+wt;
            pq.push({distance+wt,v});
           }

       }
    }
    for(auto it : dis)
    cout << it << " ";
}