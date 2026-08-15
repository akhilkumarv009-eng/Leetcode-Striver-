#include <iostream>
#include <vector>
using namespace std;
void dfs2(int n,vector <int> arr[],vector <int> &vis,vector <int> &ans)
{
   vis[n]=1;
   ans.push_back(n);
   for(auto it : arr[n])
   {
    if(vis[it]!=1)
    {
        dfs2(it,arr,vis,ans);
    }
   }
}
vector <int> dfs(int n,vector <int> arr[])
{
   vector <int> vis(n+1,0);
   vector<int> ans;
   dfs2(1,arr,vis,ans);
   return ans;
}
int main()
{
   int n,m;
   cin >> n >> m;
   vector <int> arr[n+1];
   int u,v;
   for(int i=0;i<m;i++)
   {
    cin >>u >> v;
    arr[u].push_back(v);
   }
   vector <int> ans=dfs(n,arr);
   for(auto it: ans)
   {
    cout << it << " ";

   }
}