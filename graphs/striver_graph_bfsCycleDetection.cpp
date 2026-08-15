#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int bfsCycleDetection(int src,vector<int> arr[],vector<int> &vis)
{
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(q.empty()!=1)
    {
        int node= q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it : arr[node])
        {
            if(vis[it]!=1)
            {
                vis[it]=1;
                q.push({it,node});
            }
            else
            {
                if(it!=parent && parent!=-1)
                return 1;
            }
        }
     }
    return 0;
}
int main()
{
    int n,m;
    cin >> n >> m ;
    vector<int> arr[n] ;
    int u,v ;
    for(int i=0 ; i<m ; i++)
    {
      cin >> u >> v;
      arr[u].push_back(v);
      arr[v].push_back(u);
    }
    vector<int> vis(n);
    int x = 0;
    for(int j=0;j< n;j++)
    {
        if(vis[j]!=1)
        {
            x=bfsCycleDetection(j,arr,vis);
            if(x==1)break;
        }
    }
    cout << x;
}