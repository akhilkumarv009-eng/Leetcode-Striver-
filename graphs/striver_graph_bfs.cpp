#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> BFS(int n,vector <int> arr[])
{
    vector <int> bfs;
    vector<int> vis(n + 1, 0);
    vis[1]=1;
    queue <int> q;
    q.push(1);
    while(q.empty()!=1)
    {
       int node = q.front();
       q.pop();
       bfs.push_back(node);
       for(auto it: arr[node])
       {
          if(vis[it]!=1)
          {
            q.push(it);
            vis[it]=1;
          }
       }

    }
    return bfs;
    
}
int main()
{
   int n,m;
   cin >> n >> m;
   vector <int> arr[n+1];
   int u,v;

   for(int i=0;i<m;i++)
   {
      cin >> u >> v;
      arr[u].push_back(v);
   }
   vector <int> bfs=BFS(n,arr);
    for(auto it: bfs)
       {
          cout << it << " S";
       }
}