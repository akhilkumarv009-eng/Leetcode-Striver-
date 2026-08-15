#include <iostream>
#include <vector>
using namespace std;
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
    int src=0;
    vector<int> dis(n,1e9);
    dis[src]=0; 
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(auto it: adj[j])
            {
                int v=it.first;
                int wt=it.second;
                if(dis[j]!=1e9 && dis[v]>dis[j]+wt)
                {   
                    dis[v]=dis[j]+wt ;
                }
            }
        }
    }
    for(auto it : dis)
    {
        cout << it << endl  ;
    }

}