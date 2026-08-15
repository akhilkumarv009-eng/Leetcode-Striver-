#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt}); 
        adj[v].push_back({u,wt}); 
    }
    set <pair<int,int>> st;
    int src=0;
    st.insert({0,src});
    vector<int> dis(n,1e9);
    dis[src]=0;
    while(!st.empty())
    {
       pair<int,int> node=*(st.begin());
       int distance=node.first;
       int u=node.second;
       st.erase(node);
       for(auto it : adj[u])
       {
        int v = it.first;
        int wt=it.second;
        if(dis[v]>distance+wt)
        {
             if(dis[v]!=1e9)
             {
                st.erase({dis[v],v});
             }
             dis[v]=distance+wt;
             st.insert({distance+wt,v});
        }

       }
    }
    for(auto it : dis)
    cout << it << " ";
}