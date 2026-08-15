#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>  SPalgo(vector<int> adj[],int n,int src)
{
   queue <pair<int,int>> q;
   q.push({src,0});
   vector<int> vis(n,0);
   vector<int> dis(n,-1);
   vis[src]=1;
   dis[src]=0;
   while(!q.empty())
   {
     int node = q.front().first;
     int distance=q.front().second;
     q.pop();
     for(auto it : adj[node])
     {
        if(vis[it]!=1)
        {
            dis[it]=distance+1;
            vis[it]=1;
            q.push({it,distance+1});
        }
       
     }
   }
   
   return dis;

}
int main()
{
   int n,m;
   cin >> n >> m;
   vector<int> adj[n];
   int u,v;
   for(int i=0;i<m;i++)
   {
     cin >> u >> v;
     adj[u].push_back(v);
   }
   int src=0;
   
   vector<int> ans=SPalgo(adj,n,src);
   for(auto it: ans)
   {
    cout << it << " " ;
   }
   
}