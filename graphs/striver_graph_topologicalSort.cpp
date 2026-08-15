#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs(int node,vector <int> adj[],vector<int> &vis,stack <int> &st)
{
     vis[node]=1;
     for(auto it: adj[node])
     {
        if(vis[it]!=1)
        {
            dfs(it,adj,vis,st);
        }
     }
     st.push(node);
}
int main()
{
   int n,m;
   cin >>n >> m;
   vector<int> adj[n];
   int u,v;
   for(int i=0;i<m;i++)
   {
     cin >> u >> v;
     adj[u].push_back(v);
   }
   vector<int> vis(n,0);
   stack <int> st;
   for(int i=0;i<n;i++)
   {
     if(vis[i]!=1)
     {
        dfs(i,adj,vis,st);
     }
   }
   while(st.empty()!=1)
   {
    cout << st.top() << " ";
    st.pop();
   }
}