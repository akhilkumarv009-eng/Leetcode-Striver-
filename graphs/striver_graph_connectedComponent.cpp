#include <iostream>
#include <vector>
using namespace std;
void dfs(int node,vector <int> arr[], vector<int> &vis)
{
   for(auto it : arr[node])
   {
     if(vis[it]!=1)
     {
        vis[it]=1;
        dfs(it,arr,vis);
     }
   }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> arr[n];
    int u,v;
    for(int i=0 ;i<m;i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
    }
    int count=0;
    vector <int> vis(n,0);
    for(int i=0 ;i < n;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            count++;
            dfs(i,arr,vis);
        }
    }
    cout << count << " ";

}