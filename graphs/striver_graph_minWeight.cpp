#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i<m ; i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    

   priority_queue<
   pair<int,int>,
   vector<pair<int,int>>,
   greater<pair<int,int>>
   > pq;

   pq.push({0,0});

   vector<int> vis(n,0);

   int netwt=0;

   while(!pq.empty())
   {
      int wt = pq.top().first;
      int node = pq.top().second;

      pq.pop();

      if(vis[node]!=1)
      {
         vis[node]=1;
         netwt+=wt;
         for(auto it : adj[node] )
         {
            pq.push({it.second,it.first});
         }
      }
   }
   cout << netwt ;


}