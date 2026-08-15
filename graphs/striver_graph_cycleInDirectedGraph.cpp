#include<iostream>
#include <vector>
using namespace std;
bool dfs(int n,int node,vector<int> arr[],vector<int> &vis,vector<int> &path)
{
   vis[node]=1;
   path[node]=1;
   for(auto it : arr[node])
   {
     if(vis[it]!=1)
     {
         if(!dfs(n,it,arr,vis,path))return false;
     }
     else if(path[it]==1)
     return false;
   }
   path[node]=0;
   return true;

}
int main()
{
    int n,m;
    cin >>n >> m;
    vector<int> arr[n+1];
    vector<int> vis(n+1);
    int u,v;
    for(int i=1;i<=m;i++)
    {
       cin >> u >> v;
       arr[u].push_back(v);
    }
    int h=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1)
        {
            vector<int> path(n+1,0);
            bool x = dfs(n,i,arr,vis,path);
            if(x== false)
            {
                h=0;
                cout << "cycle";
                break;
            }
        }
    }
    if(h==1)cout<<"no cycle";
}